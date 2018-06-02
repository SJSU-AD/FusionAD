// Auto-generated. Do not edit!

// (in-package velodyne_puck_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let VelodynePuckScan = require('./VelodynePuckScan.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class VelodynePuckSweep {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.scans = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('scans')) {
        this.scans = initObj.scans
      }
      else {
        this.scans = new Array(16).fill(new VelodynePuckScan());
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type VelodynePuckSweep
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Check that the constant length array field [scans] has the right length
    if (obj.scans.length !== 16) {
      throw new Error('Unable to serialize array field scans - length must be 16')
    }
    // Serialize message field [scans]
    obj.scans.forEach((val) => {
      bufferOffset = VelodynePuckScan.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type VelodynePuckSweep
    let len;
    let data = new VelodynePuckSweep(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [scans]
    len = 16;
    data.scans = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.scans[i] = VelodynePuckScan.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.scans.forEach((val) => {
      length += VelodynePuckScan.getMessageSize(val);
    });
    return length;
  }

  static datatype() {
    // Returns string type for a message object
    return 'velodyne_puck_msgs/VelodynePuckSweep';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e0395900ded93e728803e208b8b88005';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    # The 0th scan is at the bottom
    VelodynePuckScan[16] scans
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    ================================================================================
    MSG: velodyne_puck_msgs/VelodynePuckScan
    # Altitude of all the points within this scan
    float64 altitude
    
    # The valid points in this scan sorted by azimuth
    # from 0 to 359.99
    VelodynePuckPoint[] points
    
    ================================================================================
    MSG: velodyne_puck_msgs/VelodynePuckPoint
    # Time when the point is captured
    float32 time
    
    # Converted distance in the sensor frame
    float64 x
    float64 y
    float64 z
    
    # Raw measurement from velodyne puck
    float64 azimuth
    float64 distance
    float64 intensity
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new VelodynePuckSweep(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.scans !== undefined) {
      resolved.scans = new Array(16)
      for (let i = 0; i < resolved.scans.length; ++i) {
        if (msg.scans.length > i) {
          resolved.scans[i] = VelodynePuckScan.Resolve(msg.scans[i]);
        }
        else {
          resolved.scans[i] = new VelodynePuckScan();
        }
      }
    }
    else {
      resolved.scans = new Array(16).fill(new VelodynePuckScan())
    }

    return resolved;
    }
};

module.exports = VelodynePuckSweep;
