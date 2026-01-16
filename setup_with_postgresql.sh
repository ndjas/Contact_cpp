#!/bin/bash

# Script de création du projet PhonebookQt avec support PostgreSQL
# Usage: chmod +x setup_with_postgresql.sh && ./setup_with_postgresql.sh

set -e  # Arrêter en cas d'erreur

PROJECT_NAME="PhonebookQt"
BOLD='\033[1m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BOLD}=========================================="
echo -e "  🚀 Création du projet $PROJECT_NAME"
echo -e "  avec support PostgreSQL"
echo -e "==========================================${NC}"
echo ""

# Vérifier les dépendances
echo -e "${BLUE}📋 Vérification des dépendances...${NC}"

check_command() {
    if ! command -v $1 &> /dev/null; then
        echo -e "${RED}❌ $1 n'est pas installé${NC}"
        echo -e "${YELLOW}   Installez-le avec: $2${NC}"
        exit 1
    else
        echo -e "${GREEN}✅ $1 trouvé${NC}"
    fi
}

check_command qmake "sudo apt install qt5-default qtcreator"
check_command psql "sudo apt install postgresql postgresql-contrib"

echo ""

# Création de la structure
echo -e "${BLUE}📁 Création de la structure des dossiers...${NC}"
mkdir -p $PROJECT_NAME/{src/{models,views,utils,storage},lib/nlohmann,data,build}

cd $PROJECT_NAME

# Téléchargement de nlohmann/json
echo -e "${BLUE}📥 Téléchargement de nlohmann/json...${NC}"
curl -sL https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp \
     -o lib/nlohmann/json.hpp

# Fichier phonebook.json
echo -e "${BLUE}📝 Création des fichiers de configuration...${NC}"
echo "[]" > data/phonebook.json

# Fichier .pro
cat > PhonebookQt.pro << 'PROEOF'
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    src/models/Contact.cpp \
    src/models/ContactManager.cpp \
    src/storage/JSONStorage.cpp \
    src/storage/PostgresStorage.cpp \
    src/views/MainWindow.cpp \
    src/views/ContactDialog.cpp \
    src/views/PostgresConfigDialog.cpp \
    src/utils/Validator.cpp

HEADERS += \
    src/models/Contact.h \
    src/models/ContactManager.h \
    src/storage/IStorage.h \
    src/storage/JSONStorage.h \
    src/storage/PostgresStorage.h \
    src/views/MainWindow.h \
    src/views/ContactDialog.h \
    src/views/PostgresConfigDialog.h \
    src/utils/Validator.h

FORMS += \
    src/views/MainWindow.ui \
    src/views/ContactDialog.ui \
    src/views/PostgresConfigDialog.ui

INCLUDEPATH += $$PWD/lib

DESTDIR = $$PWD/build
OBJECTS_DIR = $$PWD/build/obj
MOC_DIR = $$PWD/build/moc
UI_DIR = $$PWD/build/ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
PROEOF

# main.cpp
cat > main.cpp << 'MAINEOF'
#include <QApplication>
#include "src/views/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    app.setApplicationName("MATOBEC Contact");
    app.setOrganizationName("leStatois");
    app.setApplicationVersion("2.0 - PostgreSQL Edition");
    
    MainWindow window;
    window.show();
    
    return app.exec();
}
MAINEOF

echo -e "${GREEN}✅ Structure de base créée${NC}"
echo ""

# Instructions finales
echo -e "${BOLD}=========================================="
echo -e "  ✅ Projet créé avec succès !"
echo -e "==========================================${NC}"
echo ""
echo -e "${YELLOW}📌 Prochaines étapes:${NC}"
echo ""
echo -e "${BOLD}1. Copiez les fichiers manquants depuis les artifacts:${NC}"
echo "   • src/storage/IStorage.h"
echo "   • src/storage/JSONStorage.h et .cpp"
echo "   • src/storage/PostgresStorage.h et .cpp"
echo "   • src/models/Contact.h et .cpp"
echo "   • src/models/ContactManager.h et .cpp (v2)"
echo "   • src/utils/Validator.h et .cpp"
echo "   • src/views/MainWindow.h, .cpp et .ui"
echo "   • src/views/ContactDialog.h, .cpp et .ui"
echo "   • src/views/PostgresConfigDialog.h, .cpp et .ui"
echo ""
echo -e "${BOLD}2. Configurez PostgreSQL:${NC}"
echo "   sudo -u postgres psql"
echo "   CREATE DATABASE phonebook_db;"
echo "   \q"
echo ""
echo -e "${BOLD}3. Installez les pilotes Qt PostgreSQL:${NC}"
echo "   sudo apt install libqt5sql5-psql"
echo ""
echo -e "${BOLD}4. Compilez et exécutez:${NC}"
echo "   cd $PROJECT_NAME"
echo "   qmake PhonebookQt.pro"
echo "   make"
echo "   ./build/PhonebookQt"
echo ""
echo -e "${GREEN}🎉 Bon développement !${NC}"
echo ""

# Créer un README
cat > README.md << 'READMEEOF'
# 📱 PhonebookQt - Edition PostgreSQL

Application de gestion de contacts avec double stockage JSON/PostgreSQL.

## ✨ Fonctionnalités

- ✅ Gestion complète des contacts (CRUD)
- ✅ Recherche multi-critères en temps réel
- ✅ Support JSON (fichier local)
- ✅ Support PostgreSQL (base de données)
- ✅ Basculement dynamique entre les deux modes
- ✅ Validation des données (email, téléphone, date)
- ✅ Interface moderne et intuitive

## 🚀 Installation rapide

### 1. Installer les dépendances
```bash
sudo apt install qt5-default postgresql libqt5sql5-psql
```

### 2. Créer la base de données
```bash
sudo -u postgres psql -c "CREATE DATABASE phonebook_db;"
```

### 3. Compiler
```bash
qmake PhonebookQt.pro
make
```

### 4. Lancer
```bash
./build/PhonebookQt
```

## 📖 Documentation

- `GUIDE_INSTALLATION_POSTGRESQL.md` - Guide complet PostgreSQL
- `GUIDE_COMPLET_INTEGRATION_POSTGRESQL.md` - Documentation technique

## 👤 Auteur

By @leStatois

## 📄 Licence

MIT License
READMEEOF

echo -e "${BLUE}📄 README.md créé${NC}"
