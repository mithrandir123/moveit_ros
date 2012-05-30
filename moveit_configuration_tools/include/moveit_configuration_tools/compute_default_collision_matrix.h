/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Ioan Sucan */

#ifndef MOVEIT_ROS_MOVEIT_CONFIGURATION_TOOLS_COMPUTE_DEFAULT_COLLISION_MATRIX_
#define MOVEIT_ROS_MOVEIT_CONFIGURATION_TOOLS_COMPUTE_DEFAULT_COLLISION_MATRIX_

#include <planning_scene/planning_scene.h>
#include <map>
#include <vector>
#include <string>

namespace moveit_configuration_tools
{

// LinkGraph defines a Link's model and a set of unique links it connects
typedef std::map<const planning_models::KinematicModel::LinkModel*, std::set<const planning_models::KinematicModel::LinkModel*> > LinkGraph;

// Main call for computing default collision matrix
std::map<std::string, std::vector<std::string> > 
computeDefaultCollisionMatrix(const planning_scene::PlanningSceneConstPtr &parent_scene, bool include_never_colliding = false);

// Build the robot links connection graph and then check for links with no geomotry
void
computeConnectionGraph(const planning_models::KinematicModel::LinkModel *link, LinkGraph &edges);

// Recursively build the adj list of link connections
void
computeConnectionGraphRec(const planning_models::KinematicModel::LinkModel *link, LinkGraph &edges);

}

#endif