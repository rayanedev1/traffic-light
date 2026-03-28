# 🧠 Système de Jeu de Mémoire Interactif (Arduino Simon Says)

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=4285f4&height=220&section=header&text=SIMON%20SAYS%20ENGINEERING&fontSize=45&animation=fadeIn" width="100%" />
</p>

## 📖 Introduction & Objectifs
Ce projet est une implémentation avancée d'un **système de test cognitif** basé sur microcontrôleur. L'objectif est de créer une boucle d'interaction Homme-Machine (IHM) où l'Arduino gère simultanément des sorties visuelles (LEDs), sonores (Buzzer) et des entrées utilisateur (Boutons) pour tester la mémoire à court terme.

---

## 🛠️ Architecture Matérielle (Hardware)

### 📋 Tableau de Configuration des Broches (Pins)
| Composant | Broche Arduino | Résistance | Fonction Logique |
| :--- | :--- | :--- | :--- |
| 🟢 **LED Verte** | `PIN 2` | 200 Ω | Signal Visuel 1 |
| 🔵 **LED Bleue** | `PIN 3` | 200 Ω | Signal Visuel 2 |
| 🟡 **LED Jaune** | `PIN 4` | 200 Ω | Signal Visuel 3 |
| 🔴 **LED Rouge** | `PIN 5` | 200 Ω | Signal Visuel 4 |
| 🔘 **4 Boutons** | `PINS 10-13` | Interne | Entrées de capture (INPUT_PULLUP) |
| 🔊 **Buzzer** | `PIN 9` | — | Retour Audio Multi-fréquence |

### 🔍 Analyses Techniques de l'Assemblage

#### ⚡ Gestion des Entrées : Le mode INPUT_PULLUP
Contrairement à un montage classique avec résistances externes, ce projet utilise les **résistances de tirage internes** de l'Arduino. 
* **Logique inversée :** Lorsqu'un bouton est relâché, la pin lit `HIGH` (5V). Lorsqu'il est pressé, il connecte la pin au `GND`, et la lecture devient `LOW`. 
* **Avantage :** Réduction du nombre de composants sur la breadboard et simplification du câblage.

#### 🎼 Ingénierie Sonore (Le Buzzer)
Le buzzer n'émet pas un simple "bip". Chaque LED est associée à une fréquence spécifique (en Hertz) :
* Le cerveau humain associe plus facilement une **couleur** à une **note de musique**. Cette redondance sensorielle (Vue + Ouïe) améliore l'expérience utilisateur et les scores de mémoire.

---

## 🧠 Logique de Développement (Software)

Le programme repose sur une gestion dynamique de tableaux et de générateurs aléatoires.

### 1. Génération de la Séquence (`randomSeed`)
Pour éviter que le jeu ne produise toujours la même suite de lumières, nous utilisons `randomSeed(analogRead(0))`. Cela utilise le "bruit blanc" (parasites électriques) d'une pin vide pour garantir une séquence réellement différente à chaque démarrage.

### 2. Algorithme de Vérification
Le système fonctionne selon un cycle rigoureux :
1.  **Phase d'Apprentissage :** L'Arduino parcourt le tableau `sequence[]` et allume les LEDs correspondantes.
2.  **Phase d'Écoute :** Le programme entre dans une boucle `while` bloquante, attendant une action sur les pins 10 à 13.
3.  **Comparaison en Temps Réel :** Chaque appui est immédiatement comparé à l'indice stocké. Une erreur de comparaison déclenche instantanément la fonction `gameOver()`.

---

## 🚀 Analyse de Sécurité & Stabilité
* **Anti-Rebond (Debounce) :** Le code intègre des micro-pauses (`delay(300)`) après chaque appui pour éviter que les vibrations mécaniques du bouton ne soient comptées comme plusieurs appuis.
* **Évolutivité :** La structure en tableaux permet de passer facilement de 4 à 10 LEDs ou de changer la vitesse du jeu en modifiant une seule variable de délai.

---

## 🛠️ Guide de Mise en Service

1.  **Câblage :** Connectez les cathodes (pattes courtes) des LEDs au rail bleu (GND).
2.  **Boutons :** Reliez un côté du bouton à la pin Arduino et l'autre côté directement au rail bleu (GND).
3.  **Compilation :** Utilisez l'IDE Arduino pour vérifier et téléverser le code C++.
4.  **Diagnostic :** Si aucune LED ne s'allume, vérifiez l'orientation des LEDs et la continuité de la masse (GND).

---

## 👨‍💻 Développeur
**Rayan_Dev** 🇲🇦  
> "L'ingénierie embarquée au service de l'interaction intelligente."

<p align="center">
  <a href="mailto:votre-email@gmail.com"><img src="https://img.shields.io/badge/Email-D14836?style=flat-square&logo=gmail&logoColor=white" /></a>
  &nbsp;
  <a href="https://github.com/votre-pseudo"><img src="https://img.shields.io/badge/GitHub-181717?style=flat-square&logo=github&logoColor=white" /></a>
</p>

---
<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=rect&color=4285f4&height=30&section=footer" width="100%" />
  <br>
  <i>Statut du Système : OPÉRATIONNEL | Logique de Mémoire Vérifiée</i>
</p>
