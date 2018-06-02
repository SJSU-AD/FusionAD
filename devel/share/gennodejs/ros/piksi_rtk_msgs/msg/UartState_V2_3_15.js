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

class UartState_V2_3_15 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.latency_avg = null;
      this.latency_lmin = null;
      this.latency_lmax = null;
      this.latency_current = null;
      this.obs_period_avg = null;
      this.obs_period_pmin = null;
      this.obs_period_pmax = null;
      this.obs_period_current = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('latency_avg')) {
        this.latency_avg = initObj.latency_avg
      }
      else {
        this.latency_avg = 0;
      }
      if (initObj.hasOwnProperty('latency_lmin')) {
        this.latency_lmin = initObj.latency_lmin
      }
      else {
        this.latency_lmin = 0;
      }
      if (initObj.hasOwnProperty('latency_lmax')) {
        this.latency_lmax = initObj.latency_lmax
      }
      else {
        this.latency_lmax = 0;
      }
      if (initObj.hasOwnProperty('latency_current')) {
        this.latency_current = initObj.latency_current
      }
      else {
        this.latency_current = 0;
      }
      if (initObj.hasOwnProperty('obs_period_avg')) {
        this.obs_period_avg = initObj.obs_period_avg
      }
      else {
        this.obs_period_avg = 0;
      }
      if (initObj.hasOwnProperty('obs_period_pmin')) {
        this.obs_period_pmin = initObj.obs_period_pmin
      }
      else {
        this.obs_period_pmin = 0;
      }
      if (initObj.hasOwnProperty('obs_period_pmax')) {
        this.obs_period_pmax = initObj.obs_period_pmax
      }
      else {
        this.obs_period_pmax = 0;
      }
      if (initObj.hasOwnProperty('obs_period_current')) {
        this.obs_period_current = initObj.obs_period_current
      }
      else {
        this.obs_period_current = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type UartState_V2_3_15
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [latency_avg]
    bufferOffset = _serializer.int32(obj.latency_avg, buffer, bufferOffset);
    // Serialize message field [latency_lmin]
    bufferOffset = _serializer.int32(obj.latency_lmin, buffer, bufferOffset);
    // Serialize message field [latency_lmax]
    bufferOffset = _serializer.int32(obj.latency_lmax, buffer, bufferOffset);
    // Serialize message field [latency_current]
    bufferOffset = _serializer.int32(obj.latency_current, buffer, bufferOffset);
    // Serialize message field [obs_period_avg]
    bufferOffset = _serializer.int32(obj.obs_period_avg, buffer, bufferOffset);
    // Serialize message field [obs_period_pmin]
    bufferOffset = _serializer.int32(obj.obs_period_pmin, buffer, bufferOffset);
    // Serialize message field [obs_period_pmax]
    bufferOffset = _serializer.int32(obj.obs_period_pmax, buffer, bufferOffset);
    // Serialize message field [obs_period_current]
    bufferOffset = _serializer.int32(obj.obs_period_current, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type UartState_V2_3_15
    let len;
    let data = new UartState_V2_3_15(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [latency_avg]
    data.latency_avg = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [latency_lmin]
    data.latency_lmin = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [latency_lmax]
    data.latency_lmax = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [latency_current]
    data.latency_current = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [obs_period_avg]
    data.obs_period_avg = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [obs_period_pmin]
    data.obs_period_pmin = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [obs_period_pmax]
    data.obs_period_pmax = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [obs_period_current]
    data.obs_period_current = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/UartState_V2_3_15';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'eab7c26cb7da9615284c0c7450fdcec3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The UART message reports data latency and throughput of the UART channels providing SBP I/O.
    
    # Message definition based on libsbp v2.3.15, only some field were selected for the original SBP message (same ones
    # used in piksi_tools/console/system_monitor_view.py, function "uart_state_callback").
    
    Header header
    
    int32 latency_avg               # Average latency [ms].
    int32 latency_lmin              # Minimum latency [ms].
    int32 latency_lmax              # Maximum latency [ms].
    int32 latency_current           # Smoothed estimate of the current latency [ms].
    int32 obs_period_avg            # Average period [ms].
    int32 obs_period_pmin           # Minimum period [ms].
    int32 obs_period_pmax           # Maximum period [ms].
    int32 obs_period_current        # Smoothed estimate of the current preiod [ms].
    
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
    const resolved = new UartState_V2_3_15(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.latency_avg !== undefined) {
      resolved.latency_avg = msg.latency_avg;
    }
    else {
      resolved.latency_avg = 0
    }

    if (msg.latency_lmin !== undefined) {
      resolved.latency_lmin = msg.latency_lmin;
    }
    else {
      resolved.latency_lmin = 0
    }

    if (msg.latency_lmax !== undefined) {
      resolved.latency_lmax = msg.latency_lmax;
    }
    else {
      resolved.latency_lmax = 0
    }

    if (msg.latency_current !== undefined) {
      resolved.latency_current = msg.latency_current;
    }
    else {
      resolved.latency_current = 0
    }

    if (msg.obs_period_avg !== undefined) {
      resolved.obs_period_avg = msg.obs_period_avg;
    }
    else {
      resolved.obs_period_avg = 0
    }

    if (msg.obs_period_pmin !== undefined) {
      resolved.obs_period_pmin = msg.obs_period_pmin;
    }
    else {
      resolved.obs_period_pmin = 0
    }

    if (msg.obs_period_pmax !== undefined) {
      resolved.obs_period_pmax = msg.obs_period_pmax;
    }
    else {
      resolved.obs_period_pmax = 0
    }

    if (msg.obs_period_current !== undefined) {
      resolved.obs_period_current = msg.obs_period_current;
    }
    else {
      resolved.obs_period_current = 0
    }

    return resolved;
    }
};

module.exports = UartState_V2_3_15;
