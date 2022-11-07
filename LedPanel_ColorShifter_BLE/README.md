# Bluetooth BLE Fernsteuerung mit RemoteXY



### Aufspielen/flashen des Quellcodes auf den Esp-32
1. Öffnen sie die Datei **LedPanel_ColorShifter_BLE.ino** oder laden sie sich sie hier herunter: [LedPanel_ColorShifter_BLE.ino](https://github.com/GiThUbLudwig/Codeweek_LedPanel_Esp32_iOS_and_Android/blob/325ee4223153c943bc235e9459c107d3029122a1/LedPanel_ColorShifter_BLE/LedPanel_ColorShifter_BLE.ino)
2. Öffnen sie diese in Arduino Studio
3. Suchen sie folgende Variablen im Quellcode und passen sie diese auf ihr Projekt an:
```
#define REMOTEXY_BLUETOOTH_NAME "LED-Panel-Name" //  LED-Panel-Name = der Name des Led-Panels, der ihnen angezeigt werden wird. 
```
```
int NUM_LEDS = 29;   // 29 = muss durch die Anzahl der Leds die bei ihnen verbaut sind angepasst werden. 
                     // Damit am Ende alle leuchten die verbaut wurden.
```
4. Laden sie den Quellcode auf ihr Esp32 in dem sie in Arduino Studio links oben in der Ecke auf den Pfeil nach rechts klicken (Halten sie die Boottaste auf dem Esp32 gedrückt, wenn "Connecting ....." angezeigt wird, lassen sie diese los wenn die Punkte nicht weiter fortlaufen)

![ColorshifterConnect](https://user-images.githubusercontent.com/69899600/200397546-dded2569-ee93-463f-84f6-a0170dd10e27.gif)


5. Warten sie bis das hochladen abgeschlossen ist und in der Console folgendes steht: 

![ColorshifterUpload](https://user-images.githubusercontent.com/69899600/200397561-bd658e85-4de1-4bdf-b29b-387ec0f99813.gif)

### Einrichtung von RemoteXY auf dem Mobilgerät
Damit sie ihr Led Panel steuern können, müssen sie die App RemoteXY unter folgendem Link herunterladen: [Downloadlink](https://remotexy.com/en/download/)

6. !!! WICHTIG verbinden sie **NICHT** das Esp32 mit den Bluetootheinstellungen des Mobilgerätes, sondern nur in der App!!!
Wenn sie aber zu ungeduldig waren und dies schon passiert ist starten sie wieder bei Schritt 3. und vergeben sie einen neuen Namen! Besonders bei iOS kann dies zu Problemen führen.
7. Öffnen sie die RemoteXY App und drücken sie das Plus rechts oben in der Ecke
8. Gehen sie auf Bluetooth
9. Wählen sie ihr Gerät mit dem Namen aus den sie in Schritt 3. definiert haben, hier "LED-Panel-Name"
10. Wenn sie verbunden sind können sie jetzt die Leds mit dem angezeigtem Layout steuern

<img src="https://user-images.githubusercontent.com/69899600/200094345-251e4f71-d74b-4d7d-838f-5239736ec90a.JPG" width="300" height="500">
<img>

11. Viel Spaß!

