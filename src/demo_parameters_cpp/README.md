# demo_parameters_cpp

## String Parameter Test

terminal1

```cmd
colcon build --packages-select demo_parameters_cpp
source install/setup.bash
ros2 run demo_parameters_cpp string_talker
```

terminal2

```cmd
source install/setup.bash
ros2 run demo_parameters_cpp string_listener
```

terminal3

```cmd
ros2 param set /string_talker string_param hogehoge
```

## IntArray Parameter Test

terminal1

```cmd
colcon build --packages-select demo_parameters_cpp
source install/setup.bash
ros2 run demo_parameters_cpp int_array_talker
```

terminal2

```cmd
source install/setup.bash
ros2 run demo_parameters_cpp int_array_listener
```

terminal3

```cmd
ros2 param set /in_array_talker int_array_param [0,1,5,7,7]
```

## Launch Test

### param set in launch

terminal1

```cmd
colcon build --packages-select demo_parameters_cpp
source install/setup.bash
ros2 launch demo_parameters_cpp string_topic.launch.xml
```

terminal2

```cmd
ros2 param set /string_talker string_param hogehoge
```

### param set with yaml file

terminal1

```cmd
colcon build --packages-select demo_parameters_cpp
source install/setup.bash
ros2 launch demo_parameters_cpp string_topic_with_yaml.launch.xml
```

terminal2

```cmd
ros2 param set /string_talker string_param hogehoge