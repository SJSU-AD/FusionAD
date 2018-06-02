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

class ReceiverState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.num_sat = null;
      this.rtk_mode_fix = null;
      this.sat = null;
      this.cn0 = null;
      this.tracking_running = null;
      this.system_error = null;
      this.io_error = null;
      this.swift_nap_error = null;
      this.external_antenna_present = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('num_sat')) {
        this.num_sat = initObj.num_sat
      }
      else {
        this.num_sat = 0;
      }
      if (initObj.hasOwnProperty('rtk_mode_fix')) {
        this.rtk_mode_fix = initObj.rtk_mode_fix
      }
      else {
        this.rtk_mode_fix = false;
      }
      if (initObj.hasOwnProperty('sat')) {
        this.sat = initObj.sat
      }
      else {
        this.sat = [];
      }
      if (initObj.hasOwnProperty('cn0')) {
        this.cn0 = initObj.cn0
      }
      else {
        this.cn0 = [];
      }
      if (initObj.hasOwnProperty('tracking_running')) {
        this.tracking_running = initObj.tracking_running
      }
      else {
        this.tracking_running = [];
      }
      if (initObj.hasOwnProperty('system_error')) {
        this.system_error = initObj.system_error
      }
      else {
        this.system_error = 0;
      }
      if (initObj.hasOwnProperty('io_error')) {
        this.io_error = initObj.io_error
      }
      else {
        this.io_error = 0;
      }
      if (initObj.hasOwnProperty('swift_nap_error')) {
        this.swift_nap_error = initObj.swift_nap_error
      }
      else {
        this.swift_nap_error = 0;
      }
      if (initObj.hasOwnProperty('external_antenna_present')) {
        this.external_antenna_present = initObj.external_antenna_present
      }
      else {
        this.external_antenna_present = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReceiverState
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [num_sat]
    bufferOffset = _serializer.uint8(obj.num_sat, buffer, bufferOffset);
    // Serialize message field [rtk_mode_fix]
    bufferOffset = _serializer.bool(obj.rtk_mode_fix, buffer, bufferOffset);
    // Serialize message field [sat]
    bufferOffset = _arraySerializer.uint16(obj.sat, buffer, bufferOffset, null);
    // Serialize message field [cn0]
    bufferOffset = _arraySerializer.float32(obj.cn0, buffer, bufferOffset, null);
    // Serialize message field [tracking_running]
    bufferOffset = _arraySerializer.uint8(obj.tracking_running, buffer, bufferOffset, null);
    // Serialize message field [system_error]
    bufferOffset = _serializer.uint8(obj.system_error, buffer, bufferOffset);
    // Serialize message field [io_error]
    bufferOffset = _serializer.uint8(obj.io_error, buffer, bufferOffset);
    // Serialize message field [swift_nap_error]
    bufferOffset = _serializer.uint8(obj.swift_nap_error, buffer, bufferOffset);
    // Serialize message field [external_antenna_present]
    bufferOffset = _serializer.uint8(obj.external_antenna_present, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReceiverState
    let len;
    let data = new ReceiverState(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [num_sat]
    data.num_sat = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [rtk_mode_fix]
    data.rtk_mode_fix = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [sat]
    data.sat = _arrayDeserializer.uint16(buffer, bufferOffset, null)
    // Deserialize message field [cn0]
    data.cn0 = _arrayDeserializer.float32(buffer, bufferOffset, null)
    // Deserialize message field [tracking_running]
    data.tracking_running = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [system_error]
    data.system_error = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [io_error]
    data.io_error = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [swift_nap_error]
    data.swift_nap_error = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [external_antenna_present]
    data.external_antenna_present = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 2 * object.sat.length;
    length += 4 * object.cn0.length;
    length += object.tracking_running.length;
    return length + 18;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/ReceiverState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3bca929a4e134714778225bff42f183c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Miscellaneous information form different SBP messages
    
    Header header
    
    uint8 num_sat                   # Number of satellites.
    bool rtk_mode_fix 	            # 1 = Fixed, 0 = Float.
    uint16[] sat                    # Constellation-specific satellite identifier.
    float32[] cn0                   # Carrier-to-noise density.
    uint8[] tracking_running        # Status of tracking channel.
    uint8 system_error              # System Error Flag.
    uint8 io_error                  # IO Error Flag.
    uint8 swift_nap_error           # SwiftNAP Error Flag.
    uint8 external_antenna_present  # External Antenna Present Flag.
    
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
    const resolved = new ReceiverState(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.num_sat !== undefined) {
      resolved.num_sat = msg.num_sat;
    }
    else {
      resolved.num_sat = 0
    }

    if (msg.rtk_mode_fix !== undefined) {
      resolved.rtk_mode_fix = msg.rtk_mode_fix;
    }
    else {
      resolved.rtk_mode_fix = false
    }

    if (msg.sat !== undefined) {
      resolved.sat = msg.sat;
    }
    else {
      resolved.sat = []
    }

    if (msg.cn0 !== undefined) {
      resolved.cn0 = msg.cn0;
    }
    else {
      resolved.cn0 = []
    }

    if (msg.tracking_running !== undefined) {
      resolved.tracking_running = msg.tracking_running;
    }
    else {
      resolved.tracking_running = []
    }

    if (msg.system_error !== undefined) {
      resolved.system_error = msg.system_error;
    }
    else {
      resolved.system_error = 0
    }

    if (msg.io_error !== undefined) {
      resolved.io_error = msg.io_error;
    }
    else {
      resolved.io_error = 0
    }

    if (msg.swift_nap_error !== undefined) {
      resolved.swift_nap_error = msg.swift_nap_error;
    }
    else {
      resolved.swift_nap_error = 0
    }

    if (msg.external_antenna_present !== undefined) {
      resolved.external_antenna_present = msg.external_antenna_present;
    }
    else {
      resolved.external_antenna_present = 0
    }

    return resolved;
    }
};

module.exports = ReceiverState;
