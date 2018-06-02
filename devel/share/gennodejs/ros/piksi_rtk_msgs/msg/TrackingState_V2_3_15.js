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

class TrackingState_V2_3_15 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.sat = null;
      this.code = null;
      this.fcn = null;
      this.cn0 = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('sat')) {
        this.sat = initObj.sat
      }
      else {
        this.sat = [];
      }
      if (initObj.hasOwnProperty('code')) {
        this.code = initObj.code
      }
      else {
        this.code = [];
      }
      if (initObj.hasOwnProperty('fcn')) {
        this.fcn = initObj.fcn
      }
      else {
        this.fcn = [];
      }
      if (initObj.hasOwnProperty('cn0')) {
        this.cn0 = initObj.cn0
      }
      else {
        this.cn0 = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type TrackingState_V2_3_15
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [sat]
    bufferOffset = _arraySerializer.uint8(obj.sat, buffer, bufferOffset, null);
    // Serialize message field [code]
    bufferOffset = _arraySerializer.uint8(obj.code, buffer, bufferOffset, null);
    // Serialize message field [fcn]
    bufferOffset = _arraySerializer.uint8(obj.fcn, buffer, bufferOffset, null);
    // Serialize message field [cn0]
    bufferOffset = _arraySerializer.uint8(obj.cn0, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type TrackingState_V2_3_15
    let len;
    let data = new TrackingState_V2_3_15(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [sat]
    data.sat = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [code]
    data.code = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [fcn]
    data.fcn = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [cn0]
    data.cn0 = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.sat.length;
    length += object.code.length;
    length += object.fcn.length;
    length += object.cn0.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/TrackingState_V2_3_15';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0a051c9934e022ee2abf2e31fc142ed2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The tracking message returns a variable-length array of tracking channel states. It reports status and
    # carrier-to-noise density measurements for all tracked satellites.
    
    # Message definition based on libsbp v2.3.15
    
    Header header
    
    uint8[] sat     # Constellation-specific satellite identifier.
    uint8[] code    # Signal constellation, band and code.
    uint8[] fcn     # Frequency channel number (GLONASS only).
    uint8[] cn0     # Carrier-to-Noise density. Zero implies invalid cn0 [dB Hz / 4].
    
    
    uint8 CODE_GPS_L1CA     = 0
    uint8 CODE_GPS_L2CM     = 1
    uint8 CODE_SBAS_L1CA    = 2
    uint8 CODE_GLO_L1CA     = 3
    uint8 CODE_GLO_L2CA     = 4
    uint8 CODE_GPS_L1P      = 5
    uint8 CODE_GPS_L2P      = 6
    
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
    const resolved = new TrackingState_V2_3_15(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.sat !== undefined) {
      resolved.sat = msg.sat;
    }
    else {
      resolved.sat = []
    }

    if (msg.code !== undefined) {
      resolved.code = msg.code;
    }
    else {
      resolved.code = []
    }

    if (msg.fcn !== undefined) {
      resolved.fcn = msg.fcn;
    }
    else {
      resolved.fcn = []
    }

    if (msg.cn0 !== undefined) {
      resolved.cn0 = msg.cn0;
    }
    else {
      resolved.cn0 = []
    }

    return resolved;
    }
};

// Constants for message
TrackingState_V2_3_15.Constants = {
  CODE_GPS_L1CA: 0,
  CODE_GPS_L2CM: 1,
  CODE_SBAS_L1CA: 2,
  CODE_GLO_L1CA: 3,
  CODE_GLO_L2CA: 4,
  CODE_GPS_L1P: 5,
  CODE_GPS_L2P: 6,
}

module.exports = TrackingState_V2_3_15;
