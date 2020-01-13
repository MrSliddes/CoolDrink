# CoolDrink
A project i made for the HKU G&amp;I

The readme is mostly written in Dutch language.

Tymon Versmoren HKU
If This Than That 2019-2020

!Disclaimer, ik heb dyslextie dus excuses voor enige taalfouten!

# Make it yourself
Step 1. <br>
Make sure you have the following:
- 1x Arduino Uno
- 1x 5 volt fan
- 4x mini pushbutton switches
- 5x 10K Omh resistors
- 1x 4.7K Omh resistor
- 1x wire temperature sensor (DS18B20 waterproof)
- 1x wall adapter power supply 5v to 12v (in that range)
- 1x usb cable A to B
- 1x lcd display screen 16x2 I2C
- 1x N-Channel MOSFET 60V 30A
- 1x breadbord - half size
- 1x jumper wires pack male to male
- 1x jumper wires pack male to female

Step 2.
Follow the 'wire layout' (jpg file) and put the components in the right slots. <br>
Direct link to wire layout: https://github.com/MrSliddes/CoolDrink/blob/master/VersmorenTymon_HKUITTT_CoolDrink_wirelayout.JPG
<br>
Step 3.


# Hoe ik op het idee ben gekomen en hoe ik het veder heb uitgewerkt
Toen we eenmaal de opdracht kregen om zelf iets te mogen ontwerpen met de arduino ben ik direct aan de slag gegaan. Eindelijk een project waar ik wat interesse voor had. In de pauze had ik een textdocument aangemaakt waarop ik kern woorden had getyped waarmee ik iets wilde doen. Een automatische eienpeller? Mhh nahh, wordt waarschijnlijk te moeilijk. Ik had niet echt veel inspiratie had ik niet op dat moment. Ik keek rond in de aula voor inspiratie. En toen zag ik het. 2 Klasgenoten hadden bij de kantine thee (of koffie?) gehaald en waren aan het blazen om de temperatuur kouder te krijgen. Dit was een probeel dat ik zelf ook vaak had als ik thee wilde drinken. De temperatuur was dan te hoog en dan moest je wachten tot het kouder werd, maar ik vergat meestal dat ik dan thee had en als ik het eenmaal wilde drinken was het al koud. Ik wilde dus een apparaat maken die de temperatuur meet van het drinken, waar je dan je temperatuur kunt invoeren die jij wilt hebben en dat er dan een ventilator net zo lang blijft draaien totdat de drank de gewenste temperatuur heeft bereikt. Ik keek op internet of er al componenten waren die je kon gebruiken voor arduino. Gelukkig voor mij bestonden er al temperatuur sensoren die je makkenlijk kon aansluiten en een ventilator van 5 volt.
Ik had gekozen voor een simplistische doos vorm waar ik makkelijk dingen op kon aansluiten. Ik wilde de doos zo klein mogelijk houden om makkelijk te vervoeren maar het moest wel toegangkelijk zijn voor de meeste beker maten. Ik zat nog te denken om een "arm" constructie te maken die dan de temperatuur sensor in de beker stopt maar dit maaktte het meer complex en dit was niet handig voor mij en de tijd die ik er voor had. Zeker omdat ik dit voor de eerste keer doe en ik nog nooit met electronica heb gewerkt die ik vervolgens moest lassen. De code was wel makkelijker voor mij om te schrijven omdat ik veel codeer in mijn eigen tijd. In de achterkant van de doos had ik een ruimte gemaakt zodat ik daar de bedrading kon instoppen en de arduino in het geval dat er iets kapot ging zodat ik het makkelijk kon repareren. En het is natuurlijk zonde om een arduino permanent ergens in vast te lijmen.
Dus om nog even mijn ontwerpkeuzes op te sommen:
- Het moest compact zijn voor makkelijke vervoering.
- De voorkant moest groot genoeg zijn om toegangkelijk te zijn voor de meeste bekers.
- Er moest een opening zijn in de achterkant die ik kon openmaken voor eventuele reparatie.
- Een display scherm die bestuurbaar is met vier knoppen voor makkelijke interactie voor de gebruiker (staat niet in de tekst)

# Beeldmateriaal
Dat kun je hier in dit project vinden (VersmorenTymon_ITTTVoortgangFotos.pdf) of via deze link:
https://github.com/MrSliddes/CoolDrink/blob/master/VersmorenTymon_ITTTVoortgangFotos.pdf (Foto's van mijn voortgang)

# Broncode
De code die ik voor dit project heb geschreven kun je in dit project vinden (sketch_CoolDrinkMain) of via deze link:
https://github.com/MrSliddes/CoolDrink/tree/master/sketch_CoolDrinkMain
De code is geschreven voor de arduino en is in het Engels, overal staan comments erbij die beschrijven wat de geschreven code doet.

# Blog
De dagelijkse blog kun je in dit project vinden of via deze lin:
https://github.com/MrSliddes/CoolDrink/blob/master/VersmorenTymon_ITTTBlog_v1.xlsx
