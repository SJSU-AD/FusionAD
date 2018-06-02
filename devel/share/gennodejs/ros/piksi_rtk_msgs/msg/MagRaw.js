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

class MagRaw {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.tow = null;
      this.tow_f = null;
      this.mag_x = null;
      this.mag_y = null;
      this.mag_z = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('tow')) {
        this.tow = initObj.tow
      }
      else {
        this.tow = 0;
      }
      if (initObj.hasOwnProperty('tow_f')) {
        this.tow_f = initObj.tow_f
      }
      else {
        this.tow_f = 0;
      }
      if (initObj.hasOwnProperty('mag_x')) {
        this.mag_x = initObj.mag_x
      }
      else {
        this.mag_x = 0;
      }
      if (initObj.hasOwnProperty('mag_y')) {
        this.mag_y = initObj.mag_y
      }
      else {
        this.mag_y = 0;
      }
      if (initObj.hasOwnProperty('mag_z')) {
        this.mag_z = initObj.mag_z
      }
      else {
        this.mag_z = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MagRaw
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [tow]
    bufferOffset = _serializer.uint32(obj.tow, buffer, bufferOffset);
    // Serialize message field [tow_f]
    bufferOffset = _serializer.uint8(obj.tow_f, buffer, bufferOffset);
    // Serialize message field [mag_x]
    bufferOffset = _serializer.int16(obj.mag_x, buffer, bufferOffset);
    // Serialize message field [mag_y]
    bufferOffset = _serializer.int16(obj.mag_y, buffer, bufferOffset);
    // Serialize message field [mag_z]
    bufferOffset = _serializer.int16(obj.mag_z, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MagRaw
    let len;
    let data = new MagRaw(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [tow]
    data.tow = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [tow_f]
    data.tow_f = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [mag_x]
    data.mag_x = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mag_y]
    data.mag_y = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mag_z]
    data.mag_z = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 11;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/MagRaw';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '79dfa3690a8019ef8383e9c5637520d8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Raw data from the Magnetometer.
    
    Header header
    
    uint32 tow    # Milliseconds since start of GPS week. If the high bit is set, the time is unknown or invalid.
    uint8 tow_f   # Milliseconds since start of GPS week, fractional part.
    int16 mag_x   # Magnetometer value in the body frame X axis.
    int16 mag_y   # Magnetometer value in the body frame Y axis.
    int16 mag_z   # Magnetometer value in the body frame Z axis.
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
    const resolved = new MagRaw(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.tow !== undefined) {
      resolved.tow = msg.tow;
    }
    else {
      resolved.tow = 0
    }

    if (msg.tow_f !== undefined) {
      resolved.tow_f = msg.tow_f;
    }
    else {
      resolved.tow_f = 0
    }

    if (msg.mag_x !== undefined) {
      resolved.mag_x = msg.mag_x;
    }
    else {
      resolved.mag_x = 0
    }

    if (msg.mag_y !== undefined) {
      resolved.mag_y = msg.mag_y;
    }
    else {
      resolved.mag_y = 0
    }

    if (msg.mag_z !== undefined) {
      resolved.mag_z = msg.mag_z;
    }
    else {
      resolved.mag_z = 0
    }

    return resolved;
    }
};

module.exports = MagRaw;
