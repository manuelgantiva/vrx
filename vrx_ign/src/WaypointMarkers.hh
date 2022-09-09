/*
 * Copyright (C) 2019 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef VRX_WaypointMarkers_HH_
#define VRX_WaypointMarkers_HH_

#include <memory>
#include <string>
#include <ignition/math/Vector3.hh>
#include <ignition/transport/Node.hh>
#include <sdf/sdf.hh>

namespace vrx
{
  /// \brief This class is used to display waypoint markers.
  /// Cylindrical Gazebo markers are drawn with text on top
  ///
  /// The marker properties can be set using sdf:
  /// material: Optional parameter (string type) to specify the material
  ///           for marker. Default: Gazebo/Green
  /// scaling: Optional parameter (vector type) to specify marker scaling.
  ///          Default: 0.2 0.2 1.5
  /// height: Optional parameter (double type) height of marker above water.
  /// initial_id: Optional parameter (int type) to be used as initial ID when
  /// drawing markers without explicitly specifying ID.
  /// E.g.
  /// <markers>
  ///   <material>Gazebo/Green</material>
  ///   <scaling>0.2 0.2 2.0</scaling>
  ///   <height>0.5</height>
  /// </markers>
  ///
  class WaypointMarkers
  {
    /// \brief Constructor
    /// \param[in] _namespace Marker namespace
    public: explicit WaypointMarkers(const std::string &_namespace);

    /// \brief Load marker parameters from SDF
    /// \param[in] _sdf SDF element pointer with marker parameters
    public: void Load(const std::shared_ptr<const sdf::Element> &_sdf);

    /// \brief Draw waypoint marker in Gazebo
    /// \param[in] _markerId Unique marker id for waypoint
    /// \param[in] _x X coordinate of waypoint marker
    /// \param[in] _y Y coordinate of waypoint marker
    /// \param[in] _yaw orientation of waypoint marker in radians
    /// \param[in] _text (optional) Text above waypoint marker
    /// \return Returns true if marker is successfully sent to Gazebo
    public: bool DrawMarker(int _markerId,
                            double _x,
                            double _y,
                            double _yaw,
                            const std::string &_text = "");

    /// \brief Draw a new waypoint marker in Gazebo
    /// \param[in] _x X coordinate of waypoint marker
    /// \param[in] _y Y coordinate of waypoint marker
    /// \param[in] _yaw orientation of waypoint marker in radians
    /// \param[in] _text (optional) Text above waypoint marker
    /// \return Returns true if marker is successfully sent to Gazebo
    public: bool DrawMarker(double _x,
                            double _y,
                            double _yaw,
                            const std::string &_text = "");

    /// \brief Namespace for Gazebo markers
    private: std::string ns;

    /// \brief Name of Gazebo material for marker
    private: std::string material;

    /// \brief Scaling factor for cylinder marker
    private: ignition::math::Vector3d scaling;

    /// \brief Height of marker above water
    private: double height;

    /// \brief If an ID is not specified, the markers will start using this one.
    private: int id = 0;

    /// \brief gazebo transport node
    private: ignition::transport::Node node;
  };
}

#endif
