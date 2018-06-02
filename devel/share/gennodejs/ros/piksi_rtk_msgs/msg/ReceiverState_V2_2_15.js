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

class ReceiverState_V2_2_15 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.num_sat = null;
      this.rtk_mode_fix = null;
      this.sat = null;
      this.cn0 = null;
      this.system_error = null;
      this.io_error = null;
      this.swift_nap_error = null;
      this.external_antenna_present = null;
      this.num_gps_sat = null;
      this.cn0_gps = null;
      this.num_sbas_sat = null;
      this.cn0_sbas = null;
      this.num_glonass_sat = null;
      this.cn0_glonass = null;
      this.fix_mode = null;
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
      if (initObj.hasOwnProperty('num_gps_sat')) {
        this.num_gps_sat = initObj.num_gps_sat
      }
      else {
        this.num_gps_sat = 0;
      }
      if (initObj.hasOwnProperty('cn0_gps')) {
        this.cn0_gps = initObj.cn0_gps
      }
      else {
        this.cn0_gps = [];
      }
      if (initObj.hasOwnProperty('num_sbas_sat')) {
        this.num_sbas_sat = initObj.num_sbas_sat
      }
      else {
        this.num_sbas_sat = 0;
      }
      if (initObj.hasOwnProperty('cn0_sbas')) {
        this.cn0_sbas = initObj.cn0_sbas
      }
      else {
        this.cn0_sbas = [];
      }
      if (initObj.hasOwnProperty('num_glonass_sat')) {
        this.num_glonass_sat = initObj.num_glonass_sat
      }
      else {
        this.num_glonass_sat = 0;
      }
      if (initObj.hasOwnProperty('cn0_glonass')) {
        this.cn0_glonass = initObj.cn0_glonass
      }
      else {
        this.cn0_glonass = [];
      }
      if (initObj.hasOwnProperty('fix_mode')) {
        this.fix_mode = initObj.fix_mode
      }
      else {
        this.fix_mode = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReceiverState_V2_2_15
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [num_sat]
    bufferOffset = _serializer.uint8(obj.num_sat, buffer, bufferOffset);
    // Serialize message field [rtk_mode_fix]
    bufferOffset = _serializer.bool(obj.rtk_mode_fix, buffer, bufferOffset);
    // Serialize message field [sat]
    bufferOffset = _arraySerializer.uint8(obj.sat, buffer, bufferOffset, null);
    // Serialize message field [cn0]
    bufferOffset = _arraySerializer.uint8(obj.cn0, buffer, bufferOffset, null);
    // Serialize message field [system_error]
    bufferOffset = _serializer.uint8(obj.system_error, buffer, bufferOffset);
    // Serialize message field [io_error]
    bufferOffset = _serializer.uint8(obj.io_error, buffer, bufferOffset);
    // Serialize message field [swift_nap_error]
    bufferOffset = _serializer.uint8(obj.swift_nap_error, buffer, bufferOffset);
    // Serialize message field [external_antenna_present]
    bufferOffset = _serializer.uint8(obj.external_antenna_present, buffer, bufferOffset);
    // Serialize message field [num_gps_sat]
    bufferOffset = _serializer.uint8(obj.num_gps_sat, buffer, bufferOffset);
    // Serialize message field [cn0_gps]
    bufferOffset = _arraySerializer.uint8(obj.cn0_gps, buffer, bufferOffset, null);
    // Serialize message field [num_sbas_sat]
    bufferOffset = _serializer.uint8(obj.num_sbas_sat, buffer, bufferOffset);
    // Serialize message field [cn0_sbas]
    bufferOffset = _arraySerializer.uint8(obj.cn0_sbas, buffer, bufferOffset, null);
    // Serialize message field [num_glonass_sat]
    bufferOffset = _serializer.uint8(obj.num_glonass_sat, buffer, bufferOffset);
    // Serialize message field [cn0_glonass]
    bufferOffset = _arraySerializer.uint8(obj.cn0_glonass, buffer, bufferOffset, null);
    // Serialize message field [fix_mode]
    bufferOffset = _serializer.string(obj.fix_mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReceiverState_V2_2_15
    let len;
    let data = new ReceiverState_V2_2_15(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [num_sat]
    data.num_sat = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [rtk_mode_fix]
    data.rtk_mode_fix = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [sat]
    data.sat = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [cn0]
    data.cn0 = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [system_error]
    data.system_error = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [io_error]
    data.io_error = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [swift_nap_error]
    data.swift_nap_error = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [external_antenna_present]
    data.external_antenna_present = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [num_gps_sat]
    data.num_gps_sat = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [cn0_gps]
    data.cn0_gps = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [num_sbas_sat]
    data.num_sbas_sat = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [cn0_sbas]
    data.cn0_sbas = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [num_glonass_sat]
    data.num_glonass_sat = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [cn0_glonass]
    data.cn0_glonass = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [fix_mode]
    data.fix_mode = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.sat.length;
    length += object.cn0.length;
    length += object.cn0_gps.length;
    length += object.cn0_sbas.length;
    length += object.cn0_glonass.length;
    length += object.fix_mode.length;
    return length + 33;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/ReceiverState_V2_2_15';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0b24eec3eea4c8a5bf60087436d79950';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Miscellaneous information form different SBP messages
    
    # Message definition based on libsbp v2.2.15
    
    
    Header header
    
    uint8 num_sat                   # Number of satellites.
    bool rtk_mode_fix 	            # 1 = Fixed, 0 = Float.
    uint8[] sat                     # Constellation-specific satellite identifier.
    uint8[] cn0                     # Carrier-to-Noise density. Zero implies invalid cn0 [dB Hz / 4].
    uint8 system_error              # System Error Flag.
    uint8 io_error                  # IO Error Flag.
    uint8 swift_nap_error           # SwiftNAP Error Flag.
    uint8 external_antenna_present  # External Antenna Present Flag.
    uint8 num_gps_sat               # Number of GPS satellites.
    uint8[] cn0_gps                 # Carrier-to-Noise density of GPS satellites. Zero implies invalid cn0 [dB Hz / 4].
    uint8 num_sbas_sat              # Number of SBAS satellites.
    uint8[] cn0_sbas                # Carrier-to-Noise density of SBAS satellites. Zero implies invalid cn0 [dB Hz / 4].
    uint8 num_glonass_sat           # Number of GLONASS satellites.
    uint8[] cn0_glonass             # Carrier-to-Noise density of GLONASS satellites. Zero implies invalid cn0 [dB Hz / 4].
    string fix_mode                 # Invalid, Single Point Position (SPP), Differential GNSS (DGNSS), Float RTK, Fixed RTK.
    
    
    uint8 CODE_GPS_L1CA     = 0
    uint8 CODE_GPS_L2CM     = 1
    uint8 CODE_SBAS_L1CA    = 2
    uint8 CODE_GLO_L1CA     = 3
    uint8 CODE_GLO_L2CA     = 4
    uint8 CODE_GPS_L1P      = 5
    uint8 CODE_GPS_L2P      = 6
    
    string STR_FIX_MODE_INVALID   = Invalid
    string STR_FIX_MODE_SPP       = SPP
    string STR_FIX_MODE_DGNSS     = DGNSS
    string STR_FIX_MODE_FLOAT_RTK = FLOAT_RTK
    string STR_FIX_MODE_FIXED_RTK = FIXED_RTK
    string STR_FIX_MODE_UNKNOWN   = Unknown
    
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
    const resolved = new ReceiverState_V2_2_15(null);
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

    if (msg.num_gps_sat !== undefined) {
      resolved.num_gps_sat = msg.num_gps_sat;
    }
    else {
      resolved.num_gps_sat = 0
    }

    if (msg.cn0_gps !== undefined) {
      resolved.cn0_gps = msg.cn0_gps;
    }
    else {
      resolved.cn0_gps = []
    }

    if (msg.num_sbas_sat !== undefined) {
      resolved.num_sbas_sat = msg.num_sbas_sat;
    }
    else {
      resolved.num_sbas_sat = 0
    }

    if (msg.cn0_sbas !== undefined) {
      resolved.cn0_sbas = msg.cn0_sbas;
    }
    else {
      resolved.cn0_sbas = []
    }

    if (msg.num_glonass_sat !== undefined) {
      resolved.num_glonass_sat = msg.num_glonass_sat;
    }
    else {
      resolved.num_glonass_sat = 0
    }

    if (msg.cn0_glonass !== undefined) {
      resolved.cn0_glonass = msg.cn0_glonass;
    }
    else {
      resolved.cn0_glonass = []
    }

    if (msg.fix_mode !== undefined) {
      resolved.fix_mode = msg.fix_mode;
    }
    else {
      resolved.fix_mode = ''
    }

    return resolved;
    }
};

// Constants for message
ReceiverState_V2_2_15.Constants = {
  CODE_GPS_L1CA: 0,
  CODE_GPS_L2CM: 1,
  CODE_SBAS_L1CA: 2,
  CODE_GLO_L1CA: 3,
  CODE_GLO_L2CA: 4,
  CODE_GPS_L1P: 5,
  CODE_GPS_L2P: 6,
  STR_FIX_MODE_INVALID: 'Invalid',
  STR_FIX_MODE_SPP: 'SPP',
  STR_FIX_MODE_DGNSS: 'DGNSS',
  STR_FIX_MODE_FLOAT_RTK: 'FLOAT_RTK',
  STR_FIX_MODE_FIXED_RTK: 'FIXED_RTK',
  STR_FIX_MODE_UNKNOWN: 'Unknown',
}

module.exports = ReceiverState_V2_2_15;
