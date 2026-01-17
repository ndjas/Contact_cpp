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
