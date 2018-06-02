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

class ImuRawMulti {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.tow = null;
      this.tow_f = null;
      this.acc_x = null;
      this.acc_y = null;
      this.acc_z = null;
      this.gyr_x = null;
      this.gyr_y = null;
      this.gyr_z = null;
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
      if (initObj.hasOwnProperty('acc_x')) {
        this.acc_x = initObj.acc_x
      }
      else {
        this.acc_x = 0;
      }
      if (initObj.hasOwnProperty('acc_y')) {
        this.acc_y = initObj.acc_y
      }
      else {
        this.acc_y = 0;
      }
      if (initObj.hasOwnProperty('acc_z')) {
        this.acc_z = initObj.acc_z
      }
      else {
        this.acc_z = 0;
      }
      if (initObj.hasOwnProperty('gyr_x')) {
        this.gyr_x = initObj.gyr_x
      }
      else {
        this.gyr_x = 0;
      }
      if (initObj.hasOwnProperty('gyr_y')) {
        this.gyr_y = initObj.gyr_y
      }
      else {
        this.gyr_y = 0;
      }
      if (initObj.hasOwnProperty('gyr_z')) {
        this.gyr_z = initObj.gyr_z
      }
      else {
        this.gyr_z = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ImuRawMulti
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [tow]
    bufferOffset = _serializer.uint32(obj.tow, buffer, bufferOffset);
    // Serialize message field [tow_f]
    bufferOffset = _serializer.uint8(obj.tow_f, buffer, bufferOffset);
    // Serialize message field [acc_x]
    bufferOffset = _serializer.int16(obj.acc_x, buffer, bufferOffset);
    // Serialize message field [acc_y]
    bufferOffset = _serializer.int16(obj.acc_y, buffer, bufferOffset);
    // Serialize message field [acc_z]
    bufferOffset = _serializer.int16(obj.acc_z, buffer, bufferOffset);
    // Serialize message field [gyr_x]
    bufferOffset = _serializer.int16(obj.gyr_x, buffer, bufferOffset);
    // Serialize message field [gyr_y]
    bufferOffset = _serializer.int16(obj.gyr_y, buffer, bufferOffset);
    // Serialize message field [gyr_z]
    bufferOffset = _serializer.int16(obj.gyr_z, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ImuRawMulti
    let len;
    let data = new ImuRawMulti(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [tow]
    data.tow = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [tow_f]
    data.tow_f = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [acc_x]
    data.acc_x = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [acc_y]
    data.acc_y = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [acc_z]
    data.acc_z = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gyr_x]
    data.gyr_x = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gyr_y]
    data.gyr_y = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gyr_z]
    data.gyr_z = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 17;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/ImuRawMulti';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e32f07f6279690082bb3d37f42a5fc90';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Raw data from the Inertial Measurement Unit, containing accelerometer and gyroscope readings.
    
    Header header
    
    uint32 tow    # Milliseconds since start of GPS week. If the high bit is set, the time is unknown or invalid.
    uint8 tow_f   # Milliseconds since start of GPS week, fractional part.
    int16 acc_x   # Acceleration in the body frame X axis.
    int16 acc_y   # Acceleration in the body frame Y axis.
    int16 acc_z   # Acceleration in the body frame Z axis.
    int16 gyr_x   # Angular rate around the body frame X axis.
    int16 gyr_y   # Angular rate around the body frame Y axis.
    int16 gyr_z   # Angular rate around the body frame Z axis.
    
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
    const resolved = new ImuRawMulti(null);
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

    if (msg.acc_x !== undefined) {
      resolved.acc_x = msg.acc_x;
    }
    else {
      resolved.acc_x = 0
    }

    if (msg.acc_y !== undefined) {
      resolved.acc_y = msg.acc_y;
    }
    else {
      resolved.acc_y = 0
    }

    if (msg.acc_z !== undefined) {
      resolved.acc_z = msg.acc_z;
    }
    else {
      resolved.acc_z = 0
    }

    if (msg.gyr_x !== undefined) {
      resolved.gyr_x = msg.gyr_x;
    }
    else {
      resolved.gyr_x = 0
    }

    if (msg.gyr_y !== undefined) {
      resolved.gyr_y = msg.gyr_y;
    }
    else {
      resolved.gyr_y = 0
    }

    if (msg.gyr_z !== undefined) {
      resolved.gyr_z = msg.gyr_z;
    }
    else {
      resolved.gyr_z = 0
    }

    return resolved;
    }
};

module.exports = ImuRawMulti;
