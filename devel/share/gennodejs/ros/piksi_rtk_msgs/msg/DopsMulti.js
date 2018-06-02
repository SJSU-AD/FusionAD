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

class DopsMulti {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.tow = null;
      this.gdop = null;
      this.pdop = null;
      this.tdop = null;
      this.hdop = null;
      this.vdop = null;
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
      if (initObj.hasOwnProperty('gdop')) {
        this.gdop = initObj.gdop
      }
      else {
        this.gdop = 0;
      }
      if (initObj.hasOwnProperty('pdop')) {
        this.pdop = initObj.pdop
      }
      else {
        this.pdop = 0;
      }
      if (initObj.hasOwnProperty('tdop')) {
        this.tdop = initObj.tdop
      }
      else {
        this.tdop = 0;
      }
      if (initObj.hasOwnProperty('hdop')) {
        this.hdop = initObj.hdop
      }
      else {
        this.hdop = 0;
      }
      if (initObj.hasOwnProperty('vdop')) {
        this.vdop = initObj.vdop
      }
      else {
        this.vdop = 0;
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
    // Serializes a message object of type DopsMulti
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [tow]
    bufferOffset = _serializer.uint32(obj.tow, buffer, bufferOffset);
    // Serialize message field [gdop]
    bufferOffset = _serializer.uint16(obj.gdop, buffer, bufferOffset);
    // Serialize message field [pdop]
    bufferOffset = _serializer.uint16(obj.pdop, buffer, bufferOffset);
    // Serialize message field [tdop]
    bufferOffset = _serializer.uint16(obj.tdop, buffer, bufferOffset);
    // Serialize message field [hdop]
    bufferOffset = _serializer.uint16(obj.hdop, buffer, bufferOffset);
    // Serialize message field [vdop]
    bufferOffset = _serializer.uint16(obj.vdop, buffer, bufferOffset);
    // Serialize message field [flags]
    bufferOffset = _serializer.uint8(obj.flags, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DopsMulti
    let len;
    let data = new DopsMulti(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [tow]
    data.tow = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [gdop]
    data.gdop = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [pdop]
    data.pdop = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [tdop]
    data.tdop = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [hdop]
    data.hdop = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [vdop]
    data.vdop = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [flags]
    data.flags = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 15;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/DopsMulti';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c8ec518c5a95442b85a41a69915d3477';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This dilution of precision (DOP) message describes the effect of navigation satellite geometry on positional
    # measurement precision.
    
    Header header
    
    uint32 tow  # GPS Time of Week [ms].
    uint16 gdop # Geometric Dilution of Precision.
    uint16 pdop # Position Dilution of Precision.
    uint16 tdop # Time Dilution of Precision.
    uint16 hdop # Horizontal Dilution of Precision.
    uint16 vdop # Vertical Dilution of Precision.
    uint8 flags # Indicates the position solution with which the DOPS message corresponds.
    
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
    const resolved = new DopsMulti(null);
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

    if (msg.gdop !== undefined) {
      resolved.gdop = msg.gdop;
    }
    else {
      resolved.gdop = 0
    }

    if (msg.pdop !== undefined) {
      resolved.pdop = msg.pdop;
    }
    else {
      resolved.pdop = 0
    }

    if (msg.tdop !== undefined) {
      resolved.tdop = msg.tdop;
    }
    else {
      resolved.tdop = 0
    }

    if (msg.hdop !== undefined) {
      resolved.hdop = msg.hdop;
    }
    else {
      resolved.hdop = 0
    }

    if (msg.vdop !== undefined) {
      resolved.vdop = msg.vdop;
    }
    else {
      resolved.vdop = 0
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

module.exports = DopsMulti;
