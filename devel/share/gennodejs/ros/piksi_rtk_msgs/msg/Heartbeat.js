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

class Heartbeat {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.system_error = null;
      this.io_error = null;
      this.swift_nap_error = null;
      this.sbp_minor_version = null;
      this.sbp_major_version = null;
      this.external_antenna_present = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
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
      if (initObj.hasOwnProperty('sbp_minor_version')) {
        this.sbp_minor_version = initObj.sbp_minor_version
      }
      else {
        this.sbp_minor_version = 0;
      }
      if (initObj.hasOwnProperty('sbp_major_version')) {
        this.sbp_major_version = initObj.sbp_major_version
      }
      else {
        this.sbp_major_version = 0;
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
    // Serializes a message object of type Heartbeat
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [system_error]
    bufferOffset = _serializer.uint8(obj.system_error, buffer, bufferOffset);
    // Serialize message field [io_error]
    bufferOffset = _serializer.uint8(obj.io_error, buffer, bufferOffset);
    // Serialize message field [swift_nap_error]
    bufferOffset = _serializer.uint8(obj.swift_nap_error, buffer, bufferOffset);
    // Serialize message field [sbp_minor_version]
    bufferOffset = _serializer.uint8(obj.sbp_minor_version, buffer, bufferOffset);
    // Serialize message field [sbp_major_version]
    bufferOffset = _serializer.uint8(obj.sbp_major_version, buffer, bufferOffset);
    // Serialize message field [external_antenna_present]
    bufferOffset = _serializer.uint8(obj.external_antenna_present, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Heartbeat
    let len;
    let data = new Heartbeat(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [system_error]
    data.system_error = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [io_error]
    data.io_error = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [swift_nap_error]
    data.swift_nap_error = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [sbp_minor_version]
    data.sbp_minor_version = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [sbp_major_version]
    data.sbp_major_version = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [external_antenna_present]
    data.external_antenna_present = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/Heartbeat';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f302769a534aa6ff5a3f6b1f1c11f4bc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The heartbeat message is sent periodically to inform the host or other attached devices that the system
    # is running. It is used to monitor system malfunctions. It also contains status flags that indicate to the
    # host the status of the system and whether it is operating correctly. Currently, the expected heartbeat
    # interval is 1 sec.
    # The system error flag is used to indicate that an error has occurred in the system. To determine the
    # source of the error, the remaining error flags should be inspected.
    
    Header header
    
    uint8 system_error              # System Error Flag.
    uint8 io_error                  # IO Error Flag.
    uint8 swift_nap_error           # SwiftNAP Error Flag.
    uint8 sbp_minor_version         # SBP Minor Protocol Version Number.
    uint8 sbp_major_version         # SBP Major Protocol Version Number.
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
    const resolved = new Heartbeat(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
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

    if (msg.sbp_minor_version !== undefined) {
      resolved.sbp_minor_version = msg.sbp_minor_version;
    }
    else {
      resolved.sbp_minor_version = 0
    }

    if (msg.sbp_major_version !== undefined) {
      resolved.sbp_major_version = msg.sbp_major_version;
    }
    else {
      resolved.sbp_major_version = 0
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

module.exports = Heartbeat;
