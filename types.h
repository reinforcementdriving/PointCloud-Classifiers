// Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
// @author erlangz(zhengwenchao@baidu.com)
// @date 2016/12/22 16:09:08
// @file types.h
// @brief 
#ifndef ADU_PERCEPTION_PCD_TYPES_H
#define ADU_PERCEPTION_PCD_TYPES_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include <Eigen/Geometry>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/algorithm/string.hpp>

namespace pt = boost::property_tree;

namespace adu {
namespace perception {

enum Type {
    smallMot = 0
};

class Box {
    Eigen::AngleAxisd rotation_x;
    Eigen::AngleAxisd rotation_y;
    Eigen::AngleAxisd rotation_z;
    Eigen::AlignedBox3d bounding_box;
    std::string type;
public:
    Box(const pt::ptree& root); 

    std::string debug_string() const;
    typedef std::shared_ptr<Box> Ptr;
};

class Label {
    std::string file_name;
    std::vector<Box::Ptr> boxes;
public:
    Label(const std::string& file, const pt::ptree& root);
    const std::vector<Box::Ptr>& get(const std::string file) const {
        return boxes;
    }
    std::string debug_string() const;
    typedef std::shared_ptr<Label> Ptr;
};

} //namespace perception
} //namespace adu
#endif  // ADU_PERCEPTION_PCD_TYPES_H
// 

