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

class UtcTimeMulti {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.flags = null;
      this.tow = null;
      this.year = null;
      this.month = null;
      this.day = null;
      this.hours = null;
      this.minutes = null;
      this.seconds = null;
      this.ns = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('flags')) {
        this.flags = initObj.flags
      }
      else {
        this.flags = 0;
      }
      if (initObj.hasOwnProperty('tow')) {
        this.tow = initObj.tow
      }
      else {
        this.tow = 0;
      }
      if (initObj.hasOwnProperty('year')) {
        this.year = initObj.year
      }
      else {
        this.year = 0;
      }
      if (initObj.hasOwnProperty('month')) {
        this.month = initObj.month
      }
      else {
        this.month = 0;
      }
      if (initObj.hasOwnProperty('day')) {
        this.day = initObj.day
      }
      else {
        this.day = 0;
      }
      if (initObj.hasOwnProperty('hours')) {
        this.hours = initObj.hours
      }
      else {
        this.hours = 0;
      }
      if (initObj.hasOwnProperty('minutes')) {
        this.minutes = initObj.minutes
      }
      else {
        this.minutes = 0;
      }
      if (initObj.hasOwnProperty('seconds')) {
        this.seconds = initObj.seconds
      }
      else {
        this.seconds = 0;
      }
      if (initObj.hasOwnProperty('ns')) {
        this.ns = initObj.ns
      }
      else {
        this.ns = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type UtcTimeMulti
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [flags]
    bufferOffset = _serializer.uint8(obj.flags, buffer, bufferOffset);
    // Serialize message field [tow]
    bufferOffset = _serializer.uint32(obj.tow, buffer, bufferOffset);
    // Serialize message field [year]
    bufferOffset = _serializer.uint16(obj.year, buffer, bufferOffset);
    // Serialize message field [month]
    bufferOffset = _serializer.uint8(obj.month, buffer, bufferOffset);
    // Serialize message field [day]
    bufferOffset = _serializer.uint8(obj.day, buffer, bufferOffset);
    // Serialize message field [hours]
    bufferOffset = _serializer.uint8(obj.hours, buffer, bufferOffset);
    // Serialize message field [minutes]
    bufferOffset = _serializer.uint8(obj.minutes, buffer, bufferOffset);
    // Serialize message field [seconds]
    bufferOffset = _serializer.uint8(obj.seconds, buffer, bufferOffset);
    // Serialize message field [ns]
    bufferOffset = _serializer.uint32(obj.ns, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type UtcTimeMulti
    let len;
    let data = new UtcTimeMulti(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [flags]
    data.flags = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [tow]
    data.tow = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [year]
    data.year = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [month]
    data.month = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [day]
    data.day = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [hours]
    data.hours = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [minutes]
    data.minutes = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [seconds]
    data.seconds = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [ns]
    data.ns = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/UtcTimeMulti';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '305f41bf5fdb87de324a10b06c47c614';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This message reports the Universal Coordinated Time (UTC). Note the flags which
    # indicate the source of the UTC offset value and source of the time fix.
    
    Header header
    
    uint8 flags   # Indicates source and time validity
    uint32 tow    # GPS time of week rounded to the nearest millisecond
    uint16 year   # Year
    uint8 month   # Month (range 1 .. 12)
    uint8 day     # days in the month (range 1-31)
    uint8 hours   # hours of day (range 0-23)
    uint8 minutes # minutes of hour (range 0-59)
    uint8 seconds # seconds of minute (range 0-60) rounded down
    uint32 ns     # nanoseconds of second (range 0-999999999)
    
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
    const resolved = new UtcTimeMulti(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.flags !== undefined) {
      resolved.flags = msg.flags;
    }
    else {
      resolved.flags = 0
    }

    if (msg.tow !== undefined) {
      resolved.tow = msg.tow;
    }
    else {
      resolved.tow = 0
    }

    if (msg.year !== undefined) {
      resolved.year = msg.year;
    }
    else {
      resolved.year = 0
    }

    if (msg.month !== undefined) {
      resolved.month = msg.month;
    }
    else {
      resolved.month = 0
    }

    if (msg.day !== undefined) {
      resolved.day = msg.day;
    }
    else {
      resolved.day = 0
    }

    if (msg.hours !== undefined) {
      resolved.hours = msg.hours;
    }
    else {
      resolved.hours = 0
    }

    if (msg.minutes !== undefined) {
      resolved.minutes = msg.minutes;
    }
    else {
      resolved.minutes = 0
    }

    if (msg.seconds !== undefined) {
      resolved.seconds = msg.seconds;
    }
    else {
      resolved.seconds = 0
    }

    if (msg.ns !== undefined) {
      resolved.ns = msg.ns;
    }
    else {
      resolved.ns = 0
    }

    return resolved;
    }
};

module.exports = UtcTimeMulti;
