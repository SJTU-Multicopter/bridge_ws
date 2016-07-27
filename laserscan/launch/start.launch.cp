<launch>
  <node pkg="hokuyo_node" name="hokuyo" type="hokuyo_node" respawn="false" output="screen">
    <param name="calibrate_time" type="bool" value="false"/>
    <param name="port" type="string" value="/dev/ttyACM0"/>
    <param name="intensity" type="bool" value="false"/>
    <param name="min_ang" type="double" value="-2.2689" />
    <param name="max_ang" type="double" value="2.2689" />
  </node> 
  <node pkg="laserscan" name="scan_to_cloud" type="scan_to_cloud" />
  <node pkg="laserscan" name="find_min_distance" type="find_min_distance" />
  <node pkg="lidar_lite_ros" name="lidarlite_node" type="lidarlite_node" />
  <node pkg="sonar" name="sonar_node" type="sonar_node" />
  <node pkg="sonar" name="data_handle" type="data_handle" />

  <arg name="fcu_url" default="/dev/ttyUSB0:921600" />
  <arg name="gcs_url" default="" />
  <arg name="tgt_system" default="1" />
  <arg name="tgt_component" default="1" />
  <arg name="log_output" default="screen" />
   
  <include file="$(find mavros)/launch/node.launch">
    <arg name="pluginlists_yaml" value="$(find mavros)/launch/px4_pluginlists.yaml" />
    <arg name="config_yaml" value="$(find mavros)/launch/px4_config.yaml" />

    <arg name="fcu_url" value="$(arg fcu_url)" />
    <arg name="gcs_url" value="$(arg gcs_url)" />
    <arg name="tgt_system" value="$(arg tgt_system)" />
    <arg name="tgt_component" value="$(arg tgt_component)" />
    <arg name="log_output" value="$(arg log_output)" />
  </include> 
  
</launch>

