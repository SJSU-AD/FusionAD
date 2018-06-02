// Auto-generated. Do not edit!

// (in-package piksi_rtk_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ImuAuxMulti {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.imu_type = null;
      this.temp = null;
      this.imu_conf = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('imu_type')) {
        this.imu_type = initObj.imu_type
      }
      else {
        this.imu_type = 0;
      }
      if (initObj.hasOwnProperty('temp')) {
        this.temp = initObj.temp
      }
      else {
        this.temp = 0;
      }
      if (initObj.hasOwnProperty('imu_conf')) {
        this.imu_conf = initObj.imu_conf
      }
      else {
        this.imu_conf = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ImuAuxMulti
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [imu_type]
    bufferOffset = _serializer.uint8(obj.imu_type, buffer, bufferOffset);
    // Serialize message field [temp]
    bufferOffset = _serializer.int16(obj.temp, buffer, bufferOffset);
    // Serialize message field [imu_conf]
    bufferOffset = _serializer.uint8(obj.imu_conf, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ImuAuxMulti
    let len;
    let data = new ImuAuxMulti(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [imu_type]
    data.imu_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [temp]
    data.temp = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [imu_conf]
    data.imu_conf = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/ImuAuxMulti';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1d0e477b2db08e26ff9772a2136dfba7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Auxiliary data specific to a particular IMU. The 'imu type' field will always be consistent but the rest of
    # the payload is device specific and depends on the value of 'imu type'.
    
    Header header
    
    uint8 imu_type  # IMU type.
    int16 temp      # Raw IMU temperature.
    uint8 imu_conf  # IMU configuration.
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ImuAuxMulti(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.imu_type !== undefined) {
      resolved.imu_type = msg.imu_type;
    }
    else {
      resolved.imu_type = 0
    }

    if (msg.temp !== undefined) {
      resolved.temp = msg.temp;
    }
    else {
      resolved.temp = 0
    }

    if (msg.imu_conf !== undefined) {
      resolved.imu_conf = msg.imu_conf;
    }
    else {
      resolved.imu_conf = 0
    }

    return resolved;
    }
};

module.exports = ImuAuxMulti;
