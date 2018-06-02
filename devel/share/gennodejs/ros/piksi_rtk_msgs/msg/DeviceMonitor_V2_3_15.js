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

class DeviceMonitor_V2_3_15 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.dev_vin = null;
      this.cpu_vint = null;
      this.cpu_vaux = null;
      this.cpu_temperature = null;
      this.fe_temperature = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('dev_vin')) {
        this.dev_vin = initObj.dev_vin
      }
      else {
        this.dev_vin = 0;
      }
      if (initObj.hasOwnProperty('cpu_vint')) {
        this.cpu_vint = initObj.cpu_vint
      }
      else {
        this.cpu_vint = 0;
      }
      if (initObj.hasOwnProperty('cpu_vaux')) {
        this.cpu_vaux = initObj.cpu_vaux
      }
      else {
        this.cpu_vaux = 0;
      }
      if (initObj.hasOwnProperty('cpu_temperature')) {
        this.cpu_temperature = initObj.cpu_temperature
      }
      else {
        this.cpu_temperature = 0;
      }
      if (initObj.hasOwnProperty('fe_temperature')) {
        this.fe_temperature = initObj.fe_temperature
      }
      else {
        this.fe_temperature = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DeviceMonitor_V2_3_15
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [dev_vin]
    bufferOffset = _serializer.int16(obj.dev_vin, buffer, bufferOffset);
    // Serialize message field [cpu_vint]
    bufferOffset = _serializer.int16(obj.cpu_vint, buffer, bufferOffset);
    // Serialize message field [cpu_vaux]
    bufferOffset = _serializer.int16(obj.cpu_vaux, buffer, bufferOffset);
    // Serialize message field [cpu_temperature]
    bufferOffset = _serializer.int16(obj.cpu_temperature, buffer, bufferOffset);
    // Serialize message field [fe_temperature]
    bufferOffset = _serializer.int16(obj.fe_temperature, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DeviceMonitor_V2_3_15
    let len;
    let data = new DeviceMonitor_V2_3_15(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [dev_vin]
    data.dev_vin = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [cpu_vint]
    data.cpu_vint = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [cpu_vaux]
    data.cpu_vaux = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [cpu_temperature]
    data.cpu_temperature = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [fe_temperature]
    data.fe_temperature = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 10;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/DeviceMonitor_V2_3_15';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '54b454c5f7be4348e9710a8df0100d12';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This message contains temperature and voltage level measurements from the processor’s monitoring
    # system and the RF frontend die temperature if available.
    
    # Message definition based on libsbp v2.2.15
    
    Header header
    
    int16 dev_vin               # Device V_in [V / 1000].
    int16 cpu_vint              # Processor V_int [V / 1000].
    int16 cpu_vaux              # Processor V_aux [V / 1000].
    int16 cpu_temperature       # Processor temperature [degrees C / 100].
    int16 fe_temperature        # Fronted temperature (if available) [degrees C / 100].
    
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
    const resolved = new DeviceMonitor_V2_3_15(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.dev_vin !== undefined) {
      resolved.dev_vin = msg.dev_vin;
    }
    else {
      resolved.dev_vin = 0
    }

    if (msg.cpu_vint !== undefined) {
      resolved.cpu_vint = msg.cpu_vint;
    }
    else {
      resolved.cpu_vint = 0
    }

    if (msg.cpu_vaux !== undefined) {
      resolved.cpu_vaux = msg.cpu_vaux;
    }
    else {
      resolved.cpu_vaux = 0
    }

    if (msg.cpu_temperature !== undefined) {
      resolved.cpu_temperature = msg.cpu_temperature;
    }
    else {
      resolved.cpu_temperature = 0
    }

    if (msg.fe_temperature !== undefined) {
      resolved.fe_temperature = msg.fe_temperature;
    }
    else {
      resolved.fe_temperature = 0
    }

    return resolved;
    }
};

module.exports = DeviceMonitor_V2_3_15;
