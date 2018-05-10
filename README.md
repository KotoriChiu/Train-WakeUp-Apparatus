TrainSimulator WakeUp Apparatus (模擬列車警醒裝置)
====================================
參考台鐵ATW(警醒裝置)而對遊戲"TrainSimulator"開發的警醒裝置系統

### 物件原理與說明
    本專案的程式為兩個.ino程式碼檔+一個主機偵測程式

    當踩下開關時，系統將開始倒數90秒(在開關還是踩著的狀態下)，當倒數至10秒時，
    系統將開始發出警告音(長音)，當倒數至5秒時，系統發出危險警告(急促短音)，當
    倒數至0秒時，系統會發出停車指令，列車則會停下來。

    當在踩下開關啟動倒數90秒時，在未數到0的狀況下放開開關，系統將開始倒數10秒
    若是倒數期間再次踩下開關會繼續到數90秒，否則一樣倒數到5秒時會發出危險警告
    ，0秒時發出停車指令，列車一樣會停下來。

    再來是我是怎麼做出Arduino在Serial序列埠印出字元'a'||'s' ，然後主機偵測程
    式就能偵測到並作相對應的動作，首先Arduino IDE的Serial Port並不會產生log檔
    ，所以程是無從抓到Uno板回傳的任何數據，於是我是使用 Tera Term來攔截Arduino
    回傳的數據，它會產生log檔，詳細交學我有找到一篇教學文:
    http://coopermaa2nd.blogspot.tw/2012/01/arduino.html

### 所需環境與配備(元件)
    本開發專案使用到Arduino Uno *2 蜂鳴器*1 微動開關*2以及遊戲"Train Simulator"

    那Uno接線配置有稍微的複雜 將已圖形表示 //參照專案中的Arduino.jpg圖檔

    微動開關使用兩個的原因是，要拿它來當作及閘(AND) //接線圖一樣參照Arduino.jpg圖檔

###開發中
    其實應該開發完成了owo 只是總覺得好像有甚麼功能沒加上去的...(還沒想到)
    
### 目標/功能

- [x] 微動開關踩下時會從20秒開始倒數 放開會從10秒倒數
- [x] 偵測Train Simulator是否執行中 
- [x] 當Arduino發出停車警告 發出虛擬鍵盤指令
- [x] 蜂鳴器依照秒數的變化 發出不一樣的警示

### 備註 
    Arduino.jpg待補

### 改寫開發中
    目前正在嘗試使用遊戲中的"RailDriver.dll"來進行遊戲中的讀取，這麼做的好處的是
    我可以輕鬆控制警醒裝置的啟動時機，不會再不對的時間點卻啟動警醒裝置，但目前遇到
    的困難就是還沒能夠成功的呼叫dll檔，努力嘗試中。
    一旦這個方式成功之後這個專案就可以做到以下的一些動作
-   警醒裝置會進入到遊戲中(開始駕駛)才執行
-   警醒裝置在列車時速為0的時候也不會啟動
-   如果列車是因為警醒裝置停下來的，那麼警醒裝置照樣會執行
-   可以實現ATP功能(ATP為時速安全保護裝置)