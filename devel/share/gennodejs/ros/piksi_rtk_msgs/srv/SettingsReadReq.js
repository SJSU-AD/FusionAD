// Auto-generated. Do not edit!

// (in-package piksi_rtk_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class SettingsReadReqRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.section_setting = null;
      this.setting = null;
    }
    else {
      if (initObj.hasOwnProperty('section_setting')) {
        this.section_setting = initObj.section_setting
      }
      else {
        this.section_setting = '';
      }
      if (initObj.hasOwnProperty('setting')) {
        this.setting = initObj.setting
      }
      else {
        this.setting = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SettingsReadReqRequest
    // Serialize message field [section_setting]
    bufferOffset = _serializer.string(obj.section_setting, buffer, bufferOffset);
    // Serialize message field [setting]
    bufferOffset = _serializer.string(obj.setting, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SettingsReadReqRequest
    let len;
    let data = new SettingsReadReqRequest(null);
    // Deserialize message field [section_setting]
    data.section_setting = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [setting]
    data.setting = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.section_setting.length;
    length += object.setting.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'piksi_rtk_msgs/SettingsReadReqRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5e0ca67b77ad0356e13015bb542e7b59';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    
    
    string section_setting
    string setting
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SettingsReadReqRequest(null);
    if (msg.section_setting !== undefined) {
      resolved.section_setting = msg.section_setting;
    }
    else {
      resolved.section_setting = ''
    }

    if (msg.setting !== undefined) {
      resolved.setting = msg.setting;
    }
    else {
      resolved.setting = ''
    }

    return resolved;
    }
};

class SettingsReadReqResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
      this.message = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
      if (initObj.hasOwnProperty('message')) {
        this.message = initObj.message
      }
      else {
        this.message = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SettingsReadReqResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    // Serialize message field [message]
    bufferOffset = _serializer.string(obj.message, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SettingsReadReqResponse
    let len;
    let data = new SettingsReadReqResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [message]
    data.message = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.message.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'piksi_rtk_msgs/SettingsReadReqResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '937c9679a518e3a18d831e57125ea522';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    string message
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SettingsReadReqResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    if (msg.message !== undefined) {
      resolved.message = msg.message;
    }
    else {
      resolved.message = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: SettingsReadReqRequest,
  Response: SettingsReadReqResponse,
  md5sum() { return 'd894dfc3bc541068b4b4593028b123ee'; },
  datatype() { return 'piksi_rtk_msgs/SettingsReadReq'; }
};
