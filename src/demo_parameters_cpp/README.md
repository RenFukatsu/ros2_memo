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
ros2 run demo_parameters_cpp int _array_talker
```

terminal2

```cmd
source install/setup.bash
ros2 run demo_parameters_cpp int _array_listener
```

terminal3

```cmd
ros2 param set /int _array_talker int _array_param [0,1,5,7,7]
```
