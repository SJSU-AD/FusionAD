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

class VelNed {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.tow = null;
      this.n = null;
      this.e = null;
      this.d = null;
      this.h_accuracy = null;
      this.v_accuracy = null;
      this.n_sats = null;
      this.flags = null;
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
      if (initObj.hasOwnProperty('n')) {
        this.n = initObj.n
      }
      else {
        this.n = 0;
      }
      if (initObj.hasOwnProperty('e')) {
        this.e = initObj.e
      }
      else {
        this.e = 0;
      }
      if (initObj.hasOwnProperty('d')) {
        this.d = initObj.d
      }
      else {
        this.d = 0;
      }
      if (initObj.hasOwnProperty('h_accuracy')) {
        this.h_accuracy = initObj.h_accuracy
      }
      else {
        this.h_accuracy = 0;
      }
      if (initObj.hasOwnProperty('v_accuracy')) {
        this.v_accuracy = initObj.v_accuracy
      }
      else {
        this.v_accuracy = 0;
      }
      if (initObj.hasOwnProperty('n_sats')) {
        this.n_sats = initObj.n_sats
      }
      else {
        this.n_sats = 0;
      }
      if (initObj.hasOwnProperty('flags')) {
        this.flags = initObj.flags
      }
      else {
        this.flags = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type VelNed
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [tow]
    bufferOffset = _serializer.uint32(obj.tow, buffer, bufferOffset);
    // Serialize message field [n]
    bufferOffset = _serializer.int32(obj.n, buffer, bufferOffset);
    // Serialize message field [e]
    bufferOffset = _serializer.int32(obj.e, buffer, bufferOffset);
    // Serialize message field [d]
    bufferOffset = _serializer.int32(obj.d, buffer, bufferOffset);
    // Serialize message field [h_accuracy]
    bufferOffset = _serializer.uint16(obj.h_accuracy, buffer, bufferOffset);
    // Serialize message field [v_accuracy]
    bufferOffset = _serializer.uint16(obj.v_accuracy, buffer, bufferOffset);
    // Serialize message field [n_sats]
    bufferOffset = _serializer.uint8(obj.n_sats, buffer, bufferOffset);
    // Serialize message field [flags]
    bufferOffset = _serializer.uint8(obj.flags, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type VelNed
    let len;
    let data = new VelNed(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [tow]
    data.tow = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [n]
    data.n = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [e]
    data.e = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [d]
    data.d = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [h_accuracy]
    data.h_accuracy = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [v_accuracy]
    data.v_accuracy = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [n_sats]
    data.n_sats = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [flags]
    data.flags = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 22;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/VelNed';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd181eb2c9a6abff7c97c58dc9f4c0a7f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This message reports the velocity in local North East Down (NED) coordinates. The NED coordinate
    # system is defined as the local WGS84 tangent plane centered at the current position. The full GPS time
    # is given by the preceding MSG GPS TIME with the matching time-of-week (tow).
    
    Header header
    
    uint32 tow          # GPS Time of Week.
    int32 n             # Velocity North coordinate [mm/s].
    int32 e             # Velocity East coordinate [mm/s].
    int32 d             # Velocity Down coordinate [mm/s].
    uint16 h_accuracy   # Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
    uint16 v_accuracy   # Vertical velocity accuracy estimate (not implemented). Defaults to 0.
    uint8 n_sats        # Number of satellites used in solution.
    uint8 flags         # Status flags (reserved), see MSG_VEL_ECEF message description in SBP documentation.
    
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
    const resolved = new VelNed(null);
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

    if (msg.n !== undefined) {
      resolved.n = msg.n;
    }
    else {
      resolved.n = 0
    }

    if (msg.e !== undefined) {
      resolved.e = msg.e;
    }
    else {
      resolved.e = 0
    }

    if (msg.d !== undefined) {
      resolved.d = msg.d;
    }
    else {
      resolved.d = 0
    }

    if (msg.h_accuracy !== undefined) {
      resolved.h_accuracy = msg.h_accuracy;
    }
    else {
      resolved.h_accuracy = 0
    }

    if (msg.v_accuracy !== undefined) {
      resolved.v_accuracy = msg.v_accuracy;
    }
    else {
      resolved.v_accuracy = 0
    }

    if (msg.n_sats !== undefined) {
      resolved.n_sats = msg.n_sats;
    }
    else {
      resolved.n_sats = 0
    }

    if (msg.flags !== undefined) {
      resolved.flags = msg.flags;
    }
    else {
      resolved.flags = 0
    }

    return resolved;
    }
};

module.exports = VelNed;
