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

class PosLlhMulti {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.tow = null;
      this.lat = null;
      this.lon = null;
      this.height = null;
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
      if (initObj.hasOwnProperty('lat')) {
        this.lat = initObj.lat
      }
      else {
        this.lat = 0.0;
      }
      if (initObj.hasOwnProperty('lon')) {
        this.lon = initObj.lon
      }
      else {
        this.lon = 0.0;
      }
      if (initObj.hasOwnProperty('height')) {
        this.height = initObj.height
      }
      else {
        this.height = 0.0;
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
    // Serializes a message object of type PosLlhMulti
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [tow]
    bufferOffset = _serializer.uint32(obj.tow, buffer, bufferOffset);
    // Serialize message field [lat]
    bufferOffset = _serializer.float64(obj.lat, buffer, bufferOffset);
    // Serialize message field [lon]
    bufferOffset = _serializer.float64(obj.lon, buffer, bufferOffset);
    // Serialize message field [height]
    bufferOffset = _serializer.float64(obj.height, buffer, bufferOffset);
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
    //deserializes a message object of type PosLlhMulti
    let len;
    let data = new PosLlhMulti(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [tow]
    data.tow = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [lat]
    data.lat = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [lon]
    data.lon = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [height]
    data.height = _deserializer.float64(buffer, bufferOffset);
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
    return length + 34;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/PosLlhMulti';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1432cd112c82b49dde4ea610842825ea';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This position solution message reports the absolute geodetic coordinates and the status (single point
    # vs pseudo-absolute RTK) of the position solution. If the rover receiver knows the surveyed position of
    # the base station and has an RTK solution, this reports a pseudo-absolute position solution using the
    # base station position and the rover's RTK baseline vector. The full GPS time is given by the preceding
    # MSG GPS TIME with the matching time-of-week (tow).
    
    Header header
    
    uint32 tow          # GPS Time of Week [ms].
    float64 lat         # Latitude [deg].
    float64 lon         # Longitude [deg].
    float64 height      # Height [deg].
    uint16 h_accuracy   # Horizontal position accuracy estimate.
    uint16 v_accuracy   # Vertical position accuracy estimate.
    uint8 n_sats        # Number of satellites used in solution.
    uint8 flags         # Status flags, see MSG_POS_LLH message description in SBP documentation.
    
    uint8 FIX_MODE_INVALID = 0
    uint8 FIX_MODE_SPP = 1
    uint8 FIX_MODE_DGNSS = 2
    uint8 FIX_MODE_FLOAT_RTK = 3
    uint8 FIX_MODE_FIX_RTK = 4
    uint8 FIX_MODE_DEAD_RECKONING = 5
    uint8 FIX_MODE_SBAS = 6
    
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
    const resolved = new PosLlhMulti(null);
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

    if (msg.lat !== undefined) {
      resolved.lat = msg.lat;
    }
    else {
      resolved.lat = 0.0
    }

    if (msg.lon !== undefined) {
      resolved.lon = msg.lon;
    }
    else {
      resolved.lon = 0.0
    }

    if (msg.height !== undefined) {
      resolved.height = msg.height;
    }
    else {
      resolved.height = 0.0
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

// Constants for message
PosLlhMulti.Constants = {
  FIX_MODE_INVALID: 0,
  FIX_MODE_SPP: 1,
  FIX_MODE_DGNSS: 2,
  FIX_MODE_FLOAT_RTK: 3,
  FIX_MODE_FIX_RTK: 4,
  FIX_MODE_DEAD_RECKONING: 5,
  FIX_MODE_SBAS: 6,
}

module.exports = PosLlhMulti;
