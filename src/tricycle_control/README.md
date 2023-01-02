# tricycle_control

このパッケージは作りたいものによっていろいろ頑張らないといけません。気合い入れていきましょう。  
自分でcomponentパッケージを作る場合は以下のように作成します。  

```
cd <work_dir>/src && ros2 pkg create <pkg_name> --build-type ament_cmake --dependencies rclcpp rclcpp_components rclcpp_action <other_deps> --library-name <node_name>
ex) ros2 pkg create tricycle_control --build-type ament_cmake --dependencies rclcpp rclcpp_components rclcpp_action std_msgs --library-name control_node

# CMakeLists.txtに以下を追記
rclcpp_components_register_node(
  <node_name>
  PLUGIN "<namespace::Class>"
  EXECUTABLE <preferred_name>
)

install(
  DIRECTORY
    urdf
    launch
    worlds
    config
  DESTINATION 
    share/${PROJECT_NAME}/
)

# <node_name>.hpp, <node_name>.cpp はサンプルに倣ってください。
```

componentについては別リポジトリ[ros2-template/src/custom_component/](https://github.com/husty530/ros2-template/tree/master/src/custom_component)をご覧ください。  
初期設定がめんどいですが，一度やっちゃえばあとはラクです。  
続いて，中に追加するディレクトリたちです。  

* [config](config) ... controllerを作ります。モデルのjointに対して何を制御したいのかを記述しましょう。position, velocity, effortが使えます。詳しくは[コチラ](https://qiita.com/MoriKen/items/78b0ad8c1eae257646dd)。
* [launch](launch) ... ほとんどそのままで良いですが，カスタマイズするときはパッケージ名とコントローラの種類を変えてください。
* [src](src) ... 然るべきtopicを配信するとロボットを動かせます。
* [urdf](urdf) ... .urdfファイルを新たに作成する必要があります。中身は[tricycle_description/urdf](../tricycle_description/urdf)の4つのファイルをまとめた感じです。末尾にros2_controlと書いたところがあるので，そこだけcontrollerに対応するように書き足してください。他にも，mass, transなど若干。
* [world](world) ... これは何でもいいと思います。

colcon buildでビルドに成功したら，以下のコマンドで実行します。  
```
# terminal1: execute Gazebo and several nodes about gazebo-ros2-control
ros2 launch tricycle_control tricycle_control.launch.py
# terminal2: execute C++ node
ros2 run tricycle_control exe
```

注) 筆者の環境ではたまにデーモンが正常終了できずに居座り続けることがありました。
gazebo-ros2-controlのバグらしいです。
gnome-system-monitorでタスクマネージャみたいなのを開き，python3を右クリック→killでなんとかできます。

### 参考
* [ROS2: Gazebo上のロボットをC++で制御する](https://zenn.dev/tasada038/articles/8598bb6eea5fdf)
