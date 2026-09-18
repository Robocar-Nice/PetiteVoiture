# 🚗 Robot Arduino — Contrôle Bluetooth (L298N + HC-05)

Contrôle d'un robot 2 moteurs via un pont en H **L298N**, piloté en Bluetooth depuis un smartphone Android avec l'application **Arduino Bluetooth Controller**.

Compatible avec :
- **Arduino Uno** (via `SoftwareSerial`)
- **Arduino Uno R4 Minima** (via `Serial1` matériel)

---

## 📋 Prérequis

- [Arduino IDE](https://www.arduino.cc/en/software) installé sur Windows
- Une carte **Arduino Uno** *ou* **Arduino Uno R4 Minima**
- Un module Bluetooth **HC-05** (ou HC-06)
- Un pont en H **L298N**
- Un smartphone **Android** avec l'application **Arduino Bluetooth Controller** (recherche sur le Play Store)

---

## 📁 Fichiers disponibles

| Fichier | Carte cible | Description |
|---|---|---|
| `uno_complet.ino` | Arduino Uno | Version complète et fonctionnelle |
| `uno_incomplet.ino` | Arduino Uno | Version simplifiée / à compléter |
| `uno_r4_minima_complet.ino` | Arduino Uno R4 Minima | Version complète et fonctionnelle |
| `uno_r4_minima_incomplet.ino` | Arduino Uno R4 Minima | Version simplifiée / à compléter |

> ⚠️ Les deux cartes utilisent un code différent pour la communication Bluetooth (`SoftwareSerial` vs `Serial1`) — **ne pas mélanger les fichiers entre les deux cartes**.

---

## 🔌 Câblage

### Pont en H L298N

| Arduino | L298N |
|---|---|
| 3  | IN1 |
| 4  | IN2 |
| 5  | IN3 |
| 6  | IN4 |
| 9  | ENA |
| 10 | ENB |

### Module Bluetooth HC-05

**Sur Arduino Uno :**

| Arduino | HC-05 |
|---|---|
| 11 (RX) | TXD |
| 12 (TX) | RXD *(via pont diviseur de tension)* |
| 5V | VCC |
| GND | GND |

    +----------------------+
    |     Arduino Uno      |
    |                      |
    |   3 |----------------+--------> IN1  \
    |   4 |----------------+--------> IN2   \
    |   5 |----------------+--------> IN3    |  Pont en H L298N
    |   6 |----------------+--------> IN4    |
    |   9 |----------------+--------> ENA    |
    |  10 |----------------+--------> ENB   /
    |                      |
    |  11 (RX)|------------+--------> TXD  \
    |  12 (TX)|--[diviseur]+--------> RXD   |  Bluetooth HC-05
    |                      |                /
    |                      |
    |   vin|---------------+--+-----> VIN  (L298N, 1er pin , +12V)
    |                      |
    |   5V |---------------+--+-----> VCC  (HC-05)
    |                      |
    |  GND |---------------+--+-----> GND  (L298N)
    |      |                  +-----> GND  (HC-05)
    +----------------------+


**Sur Arduino Uno R4 Minima :**

| Arduino | HC-05 |
|---|---|
| D0 (RX1) | TXD |
| D1 (TX1) | RXD *(via pont diviseur de tension)* |
| 5V | VCC |
| GND | GND |

    +----------------------+
    |  Arduino Uno R4      |
    |     Minima           |
    |                      |
    |   3 |----------------+--------> IN1  \
    |   4 |----------------+--------> IN2   \
    |   5 |----------------+--------> IN3    |  Pont en H L298N
    |   6 |----------------+--------> IN4    |
    |   9 |----------------+--------> ENA    |
    |  10 |----------------+--------> ENB   /
    |                      |
    |  D0 (RX1)|-----------+--------> TXD  \
    |  D1 (TX1)|-[diviseur]+--------> RXD   |  Bluetooth HC-05
    |                      |                /
    |                      |
    |   vin|---------------+--+-----> VIN  (L298N, 1er pin, +12V)
    |                      |
    |   5V |---------------+--+-----> VCC  (HC-05)
    |                      |
    |  GND |---------------+--+-----> GND  (L298N)
    |      |                  +-----> GND  (HC-05)
    +----------------------+

> ⚠️ Les deux moteurs doivent avoir la même configuratrion de branchement sur le pont en H (ex : OUT1 et OUT3 sur les + des moteurs respectifs ainsi que OUT2 et OUT4 sur les - desdits moteurs)


---

## 💻 Installation

1. Ouvrir **Arduino IDE**.
2. Aller dans **Fichier → Ouvrir** (ou `Ctrl + O`).
3. Sélectionner le fichier `.ino` correspondant à ta carte et à ton objectif (voir tableau ci-dessus).
4. Dans **Outils → Type de carte**, sélectionner :
   - `Arduino Uno` si tu utilises une Uno classique
   - `Arduino Uno R4 Minima` si tu utilises une R4
5. Sélectionner le bon **port COM** dans **Outils → Port**.
6. Cliquer sur **Téléverser** (flèche →).

---

## 📱 Test avec l'application Android

1. Installer **Arduino Bluetooth Controller** sur ton smartphone Android *(fonctionne uniquement sous Android)*.
2. Ouvrir l'application et sélectionner l'interface **Car Controller**.
3. Aller dans les paramètres Bluetooth du téléphone et **appairer le module HC-05** :
   - Code PIN par défaut : `1234` (ou `0000` selon le module)
4. Revenir dans l'application, sélectionner le module dans la liste et se **connecter**.
5. Utiliser les boutons directionnels pour piloter le robot.

---

## 📄 Licence

Projet personnel — libre d'utilisation et de modification.
