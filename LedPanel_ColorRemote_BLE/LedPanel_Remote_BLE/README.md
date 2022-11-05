# Bluetooth BLE Fernsteuerung mit RemoteXY



### Aufspielen/flashen des Quellcodes auf den Arduino
1. Öffnen sie die Datei **LedPanel_Remote_BLE.ino** oder laden sie sich sie hier herunter: [LedPanel_Remote_BLE.ino](https://github.com/GiThUbLudwig/Codeweek_LedPanel_Esp32_iOS_and_Android/blob/0de686a12c8844ee6ad3705e80388b1246115a12/LedPanel_ColorRemote_BLE/LedPanel_Remote_BLE/LedPanel_Remote_BLE.ino)
2. Öffnen sie diese in Arduino Studio
3. Suchen sie folgende Variablen im Quellcode und passen sie diese auf ihr Projekt an:
```
#define REMOTEXY_BLUETOOTH_NAME "LED-Panel-Name" //  LED-Panel-Name = der Name des Led-Panels, der ihnen angezeigt werden wird. 
```
```
int NUM_LEDS = 29;   // 29 = muss durch die Anzahl der Leds die bei ihnen verbaut sind angepasst werden. 
                     // Damit am Ende alle leuchten die verbaut wurden.
```
4. Laden sie den Quellcode auf ihr Esp32 in dem sie in Arduino Studio auf den Pfeil nach rechts klicken (Halten sie die Boottaste auf dem Esp32 gedrückt, wenn "Connecting ....." angezeigt wird, lassen sie diese los wenn die Punkte nicht weiter fortlaufen)

<img src="https://user-images.githubusercontent.com/69899600/200096449-d36365ee-7ae1-416d-a6da-ef456b08e47d.png" width="800" height="100">
<img>
5. Warten sie bis das hochladen abgeschlossen ist und in der Console folgendes steht: 

<img src="https://user-images.githubusercontent.com/69899600/200096531-579291b3-7b52-4352-bf11-44f1c605300d.png" width="600" height="200">
<img>
### Einrichtung von RemoteXY auf dem Mobilgerät
Damit sie ihr Led Panel steuern können, müssen sie die App unter folgendem Link herunterladen: [Downloadlink](https://remotexy.com/en/download/)

6. !!! WICHTIG verbinden sie **NICHT** das Esp32 mit den Bluetootheinstellungen des Mobilgerätes, sondern nur in der App!!!
Wenn sie aber zu ungeduldig waren und dies schon passiert ist starten sie wieder bei Schritt 3. und vergeben sie einen neuen Namen! Besonders bei iOS kann dies zu Problemen führen.
7. Öffnen sie die RemoteXY App und drücken sie das Plus rechts oben in der Ecke
8. Gehen sie auf Bluetooth
9. Wählen sie ihr Gerät mit dem Namen aus den sie in Schritt 3. definiert haben, hier "LED-Panel-Name"
10. Wenn sie verbunden sind können sie jetzt die Leds mit dem angezeigtem Layout steuern
![LedPanel_ColorRemote](https://user-images.githubusercontent.com/69899600/200095733-7032b31d-5521-40fd-8762-84669c304b59.JPG)
11. Viel Spaß!
