# mijn opzet van deze git
mijn bedoeling met deze git is om een overzicht te maken hoe je met de nodige periferie van ESP en IDF omgaat.
Door eigen componenten te maken heb je een kort en bondig overzicht van een implementatie

```
Gedaan
- GPIO 
TeDoen
```

# Als je hier een component van wil gebruiken

Als je van dit project een component wil overnemen, maak dan in de map main een nieuwe file "idf_component.yml" aan 
(als je dat nog niet had)
En voeg onderstaande tekst hierin toe (dit is het voorbeeldje voor de gpio files)

```
dependencies:

  myGPIO:
    path: components/myGPIO
    git: git@github.com:KNaelaerts/ESP32_Periferie.git

```



# omgang moet git
### 1ste keer
* ga naar github en maak een nieuwe repo aan (en copy de link)
* "git init"    dit maakt een verborgen folder met alle eigenschappen van git aan
* "git remote add origin +url"  dit legt de link tussen jouw project en de repo die je hebt aangemaakt


### als je veranderingen wil doorvoeren
* "git add ."
* "git commit -m +info"
* "git branch -M main"          -hier kies je de branch die je wil
* "git push -u origin main"

### als er veranderingen zijn (dan moet je pullen)
* ...