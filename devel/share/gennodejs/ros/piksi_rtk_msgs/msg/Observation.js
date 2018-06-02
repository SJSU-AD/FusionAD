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

class Observation {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.tow = null;
      this.ns_residual = null;
      this.wn = null;
      this.n_obs = null;
      this.P = null;
      this.L_i = null;
      this.L_f = null;
      this.D_i = null;
      this.D_f = null;
      this.cn0 = null;
      this.lock = null;
      this.flags = null;
      this.sid_sat = null;
      this.sid_code = null;
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
      if (initObj.hasOwnProperty('ns_residual')) {
        this.ns_residual = initObj.ns_residual
      }
      else {
        this.ns_residual = 0;
      }
      if (initObj.hasOwnProperty('wn')) {
        this.wn = initObj.wn
      }
      else {
        this.wn = 0;
      }
      if (initObj.hasOwnProperty('n_obs')) {
        this.n_obs = initObj.n_obs
      }
      else {
        this.n_obs = 0;
      }
      if (initObj.hasOwnProperty('P')) {
        this.P = initObj.P
      }
      else {
        this.P = [];
      }
      if (initObj.hasOwnProperty('L_i')) {
        this.L_i = initObj.L_i
      }
      else {
        this.L_i = [];
      }
      if (initObj.hasOwnProperty('L_f')) {
        this.L_f = initObj.L_f
      }
      else {
        this.L_f = [];
      }
      if (initObj.hasOwnProperty('D_i')) {
        this.D_i = initObj.D_i
      }
      else {
        this.D_i = [];
      }
      if (initObj.hasOwnProperty('D_f')) {
        this.D_f = initObj.D_f
      }
      else {
        this.D_f = [];
      }
      if (initObj.hasOwnProperty('cn0')) {
        this.cn0 = initObj.cn0
      }
      else {
        this.cn0 = [];
      }
      if (initObj.hasOwnProperty('lock')) {
        this.lock = initObj.lock
      }
      else {
        this.lock = [];
      }
      if (initObj.hasOwnProperty('flags')) {
        this.flags = initObj.flags
      }
      else {
        this.flags = [];
      }
      if (initObj.hasOwnProperty('sid_sat')) {
        this.sid_sat = initObj.sid_sat
      }
      else {
        this.sid_sat = [];
      }
      if (initObj.hasOwnProperty('sid_code')) {
        this.sid_code = initObj.sid_code
      }
      else {
        this.sid_code = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Observation
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [tow]
    bufferOffset = _serializer.uint32(obj.tow, buffer, bufferOffset);
    // Serialize message field [ns_residual]
    bufferOffset = _serializer.int32(obj.ns_residual, buffer, bufferOffset);
    // Serialize message field [wn]
    bufferOffset = _serializer.uint16(obj.wn, buffer, bufferOffset);
    // Serialize message field [n_obs]
    bufferOffset = _serializer.uint8(obj.n_obs, buffer, bufferOffset);
    // Serialize message field [P]
    bufferOffset = _arraySerializer.uint32(obj.P, buffer, bufferOffset, null);
    // Serialize message field [L_i]
    bufferOffset = _arraySerializer.int32(obj.L_i, buffer, bufferOffset, null);
    // Serialize message field [L_f]
    bufferOffset = _arraySerializer.uint8(obj.L_f, buffer, bufferOffset, null);
    // Serialize message field [D_i]
    bufferOffset = _arraySerializer.int16(obj.D_i, buffer, bufferOffset, null);
    // Serialize message field [D_f]
    bufferOffset = _arraySerializer.uint8(obj.D_f, buffer, bufferOffset, null);
    // Serialize message field [cn0]
    bufferOffset = _arraySerializer.uint8(obj.cn0, buffer, bufferOffset, null);
    // Serialize message field [lock]
    bufferOffset = _arraySerializer.uint8(obj.lock, buffer, bufferOffset, null);
    // Serialize message field [flags]
    bufferOffset = _arraySerializer.uint8(obj.flags, buffer, bufferOffset, null);
    // Serialize message field [sid_sat]
    bufferOffset = _arraySerializer.uint8(obj.sid_sat, buffer, bufferOffset, null);
    // Serialize message field [sid_code]
    bufferOffset = _arraySerializer.uint8(obj.sid_code, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Observation
    let len;
    let data = new Observation(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [tow]
    data.tow = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [ns_residual]
    data.ns_residual = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [wn]
    data.wn = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [n_obs]
    data.n_obs = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [P]
    data.P = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [L_i]
    data.L_i = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [L_f]
    data.L_f = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [D_i]
    data.D_i = _arrayDeserializer.int16(buffer, bufferOffset, null)
    // Deserialize message field [D_f]
    data.D_f = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [cn0]
    data.cn0 = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [lock]
    data.lock = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [flags]
    data.flags = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [sid_sat]
    data.sid_sat = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [sid_code]
    data.sid_code = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 4 * object.P.length;
    length += 4 * object.L_i.length;
    length += object.L_f.length;
    length += 2 * object.D_i.length;
    length += object.D_f.length;
    length += object.cn0.length;
    length += object.lock.length;
    length += object.flags.length;
    length += object.sid_sat.length;
    length += object.sid_code.length;
    return length + 51;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piksi_rtk_msgs/Observation';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9fb93688b90e872c3a77668a53e5ecc9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Satellite observation messages from the device.
    
    Header header
    
    uint32 tow                  # Milliseconds since start of GPS week.
    int32  ns_residual          # Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000).
    uint16 wn                   # GPS week number.
    uint8  n_obs                # Total number of observations.
                                # First nibble is the size of the sequence (n), second nibble is the zero-indexed counter (ith packet of n).
    
    uint32[] P                  # Pseudorange observation.
    int32[]  L_i                # Carrier phase whole cycles.
    uint8[]  L_f                # Carrier phase fractional part.
    int16[]  D_i                # Doppler whole Hz.
    uint8[]  D_f                # Doppler fractional part.
    uint8[]  cn0                # Carrier-to-Noise density. Zero implies invalid cn0.
    
    uint8[]  lock               # Lock timer.
    uint8[]  flags              # Measurement status flags.
    uint8[]  sid_sat            # Constellation-specific satellite identifier.
    uint8[]  sid_code           # Signal constellation, band and code.
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
    const resolved = new Observation(null);
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

    if (msg.ns_residual !== undefined) {
      resolved.ns_residual = msg.ns_residual;
    }
    else {
      resolved.ns_residual = 0
    }

    if (msg.wn !== undefined) {
      resolved.wn = msg.wn;
    }
    else {
      resolved.wn = 0
    }

    if (msg.n_obs !== undefined) {
      resolved.n_obs = msg.n_obs;
    }
    else {
      resolved.n_obs = 0
    }

    if (msg.P !== undefined) {
      resolved.P = msg.P;
    }
    else {
      resolved.P = []
    }

    if (msg.L_i !== undefined) {
      resolved.L_i = msg.L_i;
    }
    else {
      resolved.L_i = []
    }

    if (msg.L_f !== undefined) {
      resolved.L_f = msg.L_f;
    }
    else {
      resolved.L_f = []
    }

    if (msg.D_i !== undefined) {
      resolved.D_i = msg.D_i;
    }
    else {
      resolved.D_i = []
    }

    if (msg.D_f !== undefined) {
      resolved.D_f = msg.D_f;
    }
    else {
      resolved.D_f = []
    }

    if (msg.cn0 !== undefined) {
      resolved.cn0 = msg.cn0;
    }
    else {
      resolved.cn0 = []
    }

    if (msg.lock !== undefined) {
      resolved.lock = msg.lock;
    }
    else {
      resolved.lock = []
    }

    if (msg.flags !== undefined) {
      resolved.flags = msg.flags;
    }
    else {
      resolved.flags = []
    }

    if (msg.sid_sat !== undefined) {
      resolved.sid_sat = msg.sid_sat;
    }
    else {
      resolved.sid_sat = []
    }

    if (msg.sid_code !== undefined) {
      resolved.sid_code = msg.sid_code;
    }
    else {
      resolved.sid_code = []
    }

    return resolved;
    }
};

module.exports = Observation;
