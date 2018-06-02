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

class SettingsWriteRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.section_setting = null;
      this.setting = null;
      this.value = null;
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
      if (initObj.hasOwnProperty('value')) {
        this.value = initObj.value
      }
      else {
        this.value = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SettingsWriteRequest
    // Serialize message field [section_setting]
    bufferOffset = _serializer.string(obj.section_setting, buffer, bufferOffset);
    // Serialize message field [setting]
    bufferOffset = _serializer.string(obj.setting, buffer, bufferOffset);
    // Serialize message field [value]
    bufferOffset = _serializer.string(obj.value, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SettingsWriteRequest
    let len;
    let data = new SettingsWriteRequest(null);
    // Deserialize message field [section_setting]
    data.section_setting = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [setting]
    data.setting = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [value]
    data.value = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.section_setting.length;
    length += object.setting.length;
    length += object.value.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a service object
    return 'piksi_rtk_msgs/SettingsWriteRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5aef9698b8ca4f0cc3e8a2c7f4b64e66';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    
    
    string section_setting
    string setting
    string value
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SettingsWriteRequest(null);
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

    if (msg.value !== undefined) {
      resolved.value = msg.value;
    }
    else {
      resolved.value = ''
    }

    return resolved;
    }
};

class SettingsWriteResponse {
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
    // Serializes a message object of type SettingsWriteResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    // Serialize message field [message]
    bufferOffset = _serializer.string(obj.message, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SettingsWriteResponse
    let len;
    let data = new SettingsWriteResponse(null);
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
    return 'piksi_rtk_msgs/SettingsWriteResponse';
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
    const resolved = new SettingsWriteResponse(null);
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
  Request: SettingsWriteRequest,
  Response: SettingsWriteResponse,
  md5sum() { return '213f9437df3a9ccdceeabec724b32fdc'; },
  datatype() { return 'piksi_rtk_msgs/SettingsWrite'; }
};
