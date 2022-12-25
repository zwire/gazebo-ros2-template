# plain_vehicle_control

このパッケージは作りたいものによっていろいろ頑張らないといけません。気合い入れていきましょう。  
* [config](config) ... controllerを作ります。モデルのjointに対して何を制御したいのかを記述しましょう。position, velocity, effortが使えます。詳しくは[コチラ](https://qiita.com/MoriKen/items/78b0ad8c1eae257646dd)。
* [launch](launch) ... ほとんどそのままで良いですが，カスタマイズするときはパッケージ名とコントローラの種類を変えてください。
* [src](src) ... 然るべきtopicを配信するとロボットを動かせます。
* [urdf](urdf) ... .urdfファイルを新たに作成する必要があります。中身は[plain_vehicle_description/urdf](../plain_vehicle_description/urdf)の4つのファイルをまとめた感じです。末尾にros2_controlと書いたところがあるので，そこだけcontrollerに対応するように書き足してください。
* [world](world) ... これは何でもいいと思います。

colcon buildでビルドに成功したら，以下のコマンドで実行します。  
```
# terminal1: execute Gazebo and several nodes about gazebo-ros2-control
ros2 launch plain_vehicle_control plain_vehicle_control.launch.py
# terminal2: execute C++ node
ros2 run plain_vehicle_control exe
```

注) 筆者の環境ではたまにデーモンが正常終了できずに居座り続けることがありました。
gazebo-ros2-controlのバグらしいです。
gnome-system-monitorでタスクマネージャみたいなのを開き，python3を右クリック→killでなんとかできます。

### 参考
* [ROS2: Gazebo上のロボットをC++で制御する](https://zenn.dev/tasada038/articles/8598bb6eea5fdf)
