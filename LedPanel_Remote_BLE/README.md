# Bluetooth BLE Fernsteuerung mit RemoteXY



### Aufspielen/flashen des Quellcodes auf den Esp-32
1. Öffnet die Datei **LedPanel_Remote_BLE.ino** oder ladet sie hier herunter: [LedPanel_Remote_BLE.ino](https://github.com/GiThUbLudwig/Codeweek_LedPanel_Esp32_iOS_and_Android/blob/0de686a12c8844ee6ad3705e80388b1246115a12/LedPanel_ColorRemote_BLE/LedPanel_Remote_BLE/LedPanel_Remote_BLE.ino)
2. Öffnet diese in Arduino Studio
3. Sucht die folgenden Variablen im Quellcode und passt sie auf euer Projekt an:
```
#define REMOTEXY_BLUETOOTH_NAME "LED-Panel-Name" //  LED-Panel-Name = der Name des Led-Panels, der ihnen angezeigt werden wird. 
```
```
int NUM_LEDS = 29;   // 29 = muss durch die Anzahl der Leds die bei ihnen verbaut sind angepasst werden. 
                     // Damit am Ende alle leuchten die verbaut wurden.
```
4. Ladet den Quellcode auf euer Esp32 in dem ihr in Arduino Studio links oben in der Ecke auf den Pfeil nach rechts klickt (Haltet die Boottaste auf dem Esp32 gedrückt, wenn "Connecting ....." angezeigt wird, lasst diese los wenn die Punkte nicht weiter fortlaufen)

![ConnectingRemote](https://user-images.githubusercontent.com/69899600/200394269-1152c7e4-fa8d-4ff8-86b0-e45c508b22cb.gif)

5. Wartet bis das hochladen abgeschlossen ist und in der Console folgendes steht: 

![UploadRemote](https://user-images.githubusercontent.com/69899600/200394286-803a671b-25e6-4529-bd35-83909121798e.gif)

### Einrichtung von RemoteXY auf dem Mobilgerät
Damit ihr das Led Panel steuern könnt, müsst ihr die App RemoteXY unter folgendem Link herunterladen: [Downloadlink](https://remotexy.com/en/download/)

6. !!! WICHTIG verbindet euch **NICHT** mit dem Esp32 über die Bluetootheinstellungen des Mobilgerätes, sondern nur in der App!!!
Wenn ihr aber zu ungeduldig wart und dies schon passiert ist startet bei Schritt 3. erneut und vergebt einen neuen Namen! Besonders bei iOS kann dies zu Problemen führen.
7. Öffnet die RemoteXY App und drückt das Plus-Symbol rechts oben in der Ecke
    - Geht auf Bluetooth
    - Wählt das Gerät mit dem Namen aus den ihr in Schritt 3. definiert habt, hier "LED-Panel-Name"
    - Wenn es verbunden ist könnt ihr jetzt die Leds mit dem angezeigtem Layout steuern

![RemoteConnectingApp](https://user-images.githubusercontent.com/69899600/200401220-5faa70ea-0b9b-47b4-8f72-aa64ce48e83f.gif)

8. Viel Spaß!
