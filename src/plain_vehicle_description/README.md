# plain_vehicle_description

[fusion2urdf ROS2](https://github.com/dheena2k2/fusion2urdf-ros2)により自動生成されたフォルダです。何もいじってません。  
[Fusion 360](https://www.autodesk.co.jp/campaigns/design-now)でモデルを作成した時点では"plain_vehicle"というプロジェクト名をつけました。urdfが生成される際に"..._description"という名前が勝手につきます。  

* [meshes](meshes) ... STLファイルが入っています。
* [launch](launch) ... 2つのlaunchファイルがあります。動作確認に。モデルがマズイ or 何らかのインストール不足だとここでエラーが出ます。

これを思い通り制御するにはもう一つのパッケージ[plain_vehicle_control](../plain_vehicle_control)からこちらを参照します。
