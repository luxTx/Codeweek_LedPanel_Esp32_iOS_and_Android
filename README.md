# Codeweek_LedPanel_Esp32_iOS_-_Android
## [Ratisbonacoding e.V.](https://ratisbona-coding.org/)     X     [MINT-Labs Regensburg](https://www.mint-labs-regensburg.de/)

Librarys needed:
RemoteXY
Adafruit

// GIF MIT PANEL BEISPIEL EINFÜGEN

Dieses Repository enthält den Quellcode für ein Led-Panel basierend auf einem ESP-32. Das Ziel der 
[Veranstaltung](https://bayern.codeweek.de/programm/veranstaltung/2022-10-07-steuerung-einer-led-lampe) 
war es, ein Led-Panel zu bauen das mithilfe eines Mobilgerätes, von einem Tablet oder Smartphone über Bluetooth gesteuert werden kann.


## Repository Aufbau

- Hier findet ihr die Beschreibung, wie ihr eure Entwicklungsumgebung aufsetzen müsst und wie das Hardware-Setup grundsätzlich aufgebaut ist.
- Im Ordner `RemoteXY` findet ihr den Quellcode, sowie eine Anleitung zum aufspielen/flashen des Quellcodes auf den ESP-32.

## Entwicklungsumgebung

### Arduino Studio 1.8.19

Hier herunterladen https://downloads.arduino.cc/arduino-1.8.19-windows.exe und installieren.

#### ESP32 Board

Dann müssen wir die board Bibliothek für das ESP32 board installieren:

* `File > Preferences > Additional Board Manager Urls`: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json eintragen
* `Tools > Board > Board Manager` suchen nach ESP32 und installieren

[Esp32BoardManager](https://user-images.githubusercontent.com/69899600/200091466-2ec865a3-b5e8-44c1-8f2f-9e3639333fe1.jpg)

<img src="https://user-images.githubusercontent.com/69899600/200091466-2ec865a3-b5e8-44c1-8f2f-9e3639333fe1.jpg" width="500" height="300"  />
<img>

#### Adafruit Bibliothek

* Downloadlink der Bibliothek: https://github.com/adafruit/Adafruit_NeoPixel
* `Sketch > Include Library > Manage Libraries` suche nach `Adafruit NeoPixel` und dann installieren (nicht esp32servo360).

[AdafruitNeoPixelBibliothek](https://user-images.githubusercontent.com/69899600/200089927-83541b62-df84-4651-a997-0bbd690aa709.jpg)

<img src="https://user-images.githubusercontent.com/69899600/200089927-83541b62-df84-4651-a997-0bbd690aa709.jpg" width="500" height="300" />
<img>

#### RemoteXY Bibliothek

* Downloadlink der Bibliothek(Direktlink): https://remotexy.com/en/library/
* `Sketch > Include Library > Manage Libraries` suche nach `RemoteXY` und dann installieren (nicht esp32servo360).

[RemoteXYBibliothek](https://user-images.githubusercontent.com/69899600/200091219-74b7ca30-0d31-4203-83a9-6ee3d4292763.jpg)

<img src="https://user-images.githubusercontent.com/69899600/200091219-74b7ca30-0d31-4203-83a9-6ee3d4292763.jpg" width="500" height="300" />
<img>

#### Board einrichten

* `Tools > Board > Esp32 Arduino` und wählt dort `ESP32 Dev Module` aus.

## Hardware-Liste

- [ ] Esp32
- [ ] Led-Streifen
- [ ] Kabel
- [ ] 5V-Buchse
- [ ] Ikea-Ribba
- [ ] Plexiglass-/Milchglassplatte

#### Tools
- [ ] Lötkobeln
- [ ] Heissklebepistole

## Hardware - Setup 

| Led Stripe  | ESP32 | Funktion |
| ------------- | ------------- | ------------- |
| 5V   | VIN	| Spannungsversorgung (+) |
| GND	| GND	| Spannungsversorgung (-) |
| ENA	| GPIO18	| Led Signal |

#### Schaltplan - Schematic

![Schematic]()

## Anhang

### ESP32 Pinout

![Az-DeliveryEsp32BoardSpecs](https://user-images.githubusercontent.com/69899600/200091632-76cfbde5-0814-4d0d-8f4c-69005b0f8844.JPG)

[Bildquelle](https://cdn.shopify.com/s/files/1/1509/1638/files/ESP_-_32_NodeMCU_Developmentboard_Pinout_Diagram.jpg?4479111012146266271)

### Led Pinout
<img src="https://user-images.githubusercontent.com/69899600/200092172-0dff7649-3f32-410e-a05a-3ecc311b0f3a.JPG" width="400" height="400" />
<img>

[Bildquelle](https://m.media-amazon.com/images/I/613Ob9Me-GL._AC_SL1100_.jpg)
