//元ネタ→https://www.youtube.com/watch?v=REGhsgB4NyE
//これは音が鳴るときにLEDが光るようにコードを追加したバージョン

//CapacitiveSensor Libraryのダウンロード
//下のURL開いてCode↓ボタン→downloadZip
//https://github.com/PaulStoffregen/CapacitiveSensor
//ダウンロードしたら、arduinoIDEでスケッチ→ライブラリをインクルード→.zip形式のライブラリをインストール→CapacitiveSensor-master.zipを選ぶ
//インクルードしたら一回arduinoIDE終了して再起動

#include <CapacitiveSensor.h>
CapacitiveSensor capSensor1 = CapacitiveSensor(4,2);
CapacitiveSensor capSensor2 = CapacitiveSensor(7,5);

int threshold = 1000;
const int ledPin = 12;

void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
}

void loop() {
  long sensorValue1 = capSensor1.capacitiveSensor(30); //
  long sensorValue2 = capSensor2.capacitiveSensor(30); //

    Serial.print("Sensor1: ");
    Serial.print(sensorValue1);
    Serial.print("Sensor2: ");
    Serial.println(sensorValue2);

    if (sensorValue2 > threshold) {
    // turn the LED on
    digitalWrite(ledPin, HIGH);//LEDを光らす
  }
  // if it's lower than the threshold
  else {
    // turn the LED off
    digitalWrite(ledPin, LOW);//LEDを消す
  }
  delay(10);
    
    //map(value, fromLow（現在の範囲の下限）, fromHigh（現在の範囲の上限）, toLow（変換後の範囲の下限）, toHigh（変換後の範囲の下限）)
    int val1 = map(sensorValue1, 0, 5000, 50, 4000); //sensorValue1で読み取った数値をtone用（周波数）に変換する
    //int val1 = map(sensorValue1, 0, 1000, 50, 528); //変換する上限値や下限値を変更すると音が変わる
    int val2 = map(sensorValue2, 0, 10000, 10, 1000); //sensorValue2で読み取った数値をdelay用（音の長さ）に変換する
    //int val2 = map(sensorValue2, 0, 5000, 50, 4000); //変換する上限値や下限値を変更すると音のなり方が変わる

    tone(8,val1,20);//tone(pin, 周波数, 音の持続時間)
    //tone(8,val1,100);//tone(pin, 周波数, 音の持続時間)音の持続時間の値を変えると音のなりかたが変わる
    noTone;//パルスの停止
    delay(val2);
}
