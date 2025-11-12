#include "hub.h"
#include "esphome/core/helpers.h"

#include <string>

namespace esphome {
namespace opentherm {

static const char *const TAG = "opentherm";
namespace message_data {
bool parse_flag8_lb_0(OpenthermData &data) { return read_bit(data.valueLB, 0); }
bool parse_flag8_lb_1(OpenthermData &data) { return read_bit(data.valueLB, 1); }
bool parse_flag8_lb_2(OpenthermData &data) { return read_bit(data.valueLB, 2); }
bool parse_flag8_lb_3(OpenthermData &data) { return read_bit(data.valueLB, 3); }
bool parse_flag8_lb_4(OpenthermData &data) { return read_bit(data.valueLB, 4); }
bool parse_flag8_lb_5(OpenthermData &data) { return read_bit(data.valueLB, 5); }
bool parse_flag8_lb_6(OpenthermData &data) { return read_bit(data.valueLB, 6); }
bool parse_flag8_lb_7(OpenthermData &data) { return read_bit(data.valueLB, 7); }
bool parse_flag8_hb_0(OpenthermData &data) { return read_bit(data.valueHB, 0); }
bool parse_flag8_hb_1(OpenthermData &data) { return read_bit(data.valueHB, 1); }
bool parse_flag8_hb_2(OpenthermData &data) { return read_bit(data.valueHB, 2); }
bool parse_flag8_hb_3(OpenthermData &data) { return read_bit(data.valueHB, 3); }
bool parse_flag8_hb_4(OpenthermData &data) { return read_bit(data.valueHB, 4); }
bool parse_flag8_hb_5(OpenthermData &data) { return read_bit(data.valueHB, 5); }
bool parse_flag8_hb_6(OpenthermData &data) { return read_bit(data.valueHB, 6); }
bool parse_flag8_hb_7(OpenthermData &data) { return read_bit(data.valueHB, 7); }
uint8_t parse_u8_lb(OpenthermData &data) { return data.valueLB; }
uint8_t parse_u8_hb(OpenthermData &data) { return data.valueHB; }
int8_t parse_s8_lb(OpenthermData &data) { return (int8_t) data.valueLB; }
int8_t parse_s8_hb(OpenthermData &data) { return (int8_t) data.valueHB; }
uint16_t parse_u16(OpenthermData &data) { return data.u16(); }
uint16_t parse_u8_lb_60(OpenthermData &data) { return data.valueLB * 60; }
uint16_t parse_u8_hb_60(OpenthermData &data) { return data.valueHB * 60; }
int16_t parse_s16(OpenthermData &data) { return data.s16(); }
float parse_f88(OpenthermData &data) { return data.f88(); }

void write_flag8_lb_0(const bool value, OpenthermData &data) { data.valueLB = write_bit(data.valueLB, 0, value); }
void write_flag8_lb_1(const bool value, OpenthermData &data) { data.valueLB = write_bit(data.valueLB, 1, value); }
void write_flag8_lb_2(const bool value, OpenthermData &data) { data.valueLB = write_bit(data.valueLB, 2, value); }
void write_flag8_lb_3(const bool value, OpenthermData &data) { data.valueLB = write_bit(data.valueLB, 3, value); }
void write_flag8_lb_4(const bool value, OpenthermData &data) { data.valueLB = write_bit(data.valueLB, 4, value); }
void write_flag8_lb_5(const bool value, OpenthermData &data) { data.valueLB = write_bit(data.valueLB, 5, value); }
void write_flag8_lb_6(const bool value, OpenthermData &data) { data.valueLB = write_bit(data.valueLB, 6, value); }
void write_flag8_lb_7(const bool value, OpenthermData &data) { data.valueLB = write_bit(data.valueLB, 7, value); }
void write_flag8_hb_0(const bool value, OpenthermData &data) { data.valueHB = write_bit(data.valueHB, 0, value); }
void write_flag8_hb_1(const bool value, OpenthermData &data) { data.valueHB = write_bit(data.valueHB, 1, value); }
void write_flag8_hb_2(const bool value, OpenthermData &data) { data.valueHB = write_bit(data.valueHB, 2, value); }
void write_flag8_hb_3(const bool value, OpenthermData &data) { data.valueHB = write_bit(data.valueHB, 3, value); }
void write_flag8_hb_4(const bool value, OpenthermData &data) { data.valueHB = write_bit(data.valueHB, 4, value); }
void write_flag8_hb_5(const bool value, OpenthermData &data) { data.valueHB = write_bit(data.valueHB, 5, value); }
void write_flag8_hb_6(const bool value, OpenthermData &data) { data.valueHB = write_bit(data.valueHB, 6, value); }
void write_flag8_hb_7(const bool value, OpenthermData &data) { data.valueHB = write_bit(data.valueHB, 7, value); }
void write_u8_lb(const uint8_t value, OpenthermData &data) { data.valueLB = value; }
void write_u8_hb(const uint8_t value, OpenthermData &data) { data.valueHB = value; }
void write_s8_lb(const int8_t value, OpenthermData &data) { data.valueLB = (uint8_t) value; }
void write_s8_hb(const int8_t value, OpenthermData &data) { data.valueHB = (uint8_t) value; }
void write_u16(const uint16_t value, OpenthermData &data) { data.u16(value); }
void write_s16(const int16_t value, OpenthermData &data) { data.s16(value); }
void write_f88(const float value, OpenthermData &data) { data.f88(value); }

}  // namespace message_data

OpenthermData OpenthermHub::build_request_(MessageId request_id) const {
  OpenthermData data;
  data.type = 0;
  data.id = request_id;
  data.valueHB = 0;
  data.valueLB = 0;

  #include <math.h>
  auto pack_f88 = [](float v){ if(v<0)v=0; if(v>255.996f)v=255.996f; return (uint16_t)lroundf(v*256.0f); };

  if (request_id == static_cast<MessageId>(7)) {
    OpenthermData d; d.id = request_id;
    d.type = MessageType::READ_DATA;        // ← i.p.v. WRITE_DATA
    d.valueHB = 0;
    d.valueLB = 0;
    return d;
  }

  if (request_id == static_cast<MessageId>(0)) {  // STATUS
    OpenthermData d; d.id = request_id;
    if (this->cooling_enable && ((this->cool_write_cycle_++ % 5u) == 0u)) {
      d.type = MessageType::WRITE_DATA;
      d.valueHB = 0x06;   // 0x0600 => CoolingEnable=ON (CH=0, DHW=1, COOL=1)
      d.valueLB = 0x00;
      ESP_LOGD("opentherm", "FORCE WRITE STATUS 0x0600 (cool enable)");
      return d;
    }
    d.type = MessageType::READ_DATA;   // default
    d.valueHB = 0x00; d.valueLB = 0x00;
    return d;
  }

  // (optioneel) ID 14: Max modulation = 100% bij koelen
  if (request_id == static_cast<MessageId>(14)) {
    OpenthermData d; d.id = request_id;
    if (this->cooling_enable) {
      d.type = MessageType::WRITE_DATA;
      uint16_t w = pack_f88(100.0f);
      d.valueHB = w >> 8; d.valueLB = w & 0xFF;
    } else {
      d.type = MessageType::READ_DATA;
    }
    return d;
  }

  // We need this special logic for STATUS message because we have two options for specifying boiler modes:
  // with static config values in the hub, or with separate switches.
  if (request_id == MessageId::STATUS) {
    // Als er iets veranderde of we staan op WRITE, schrijf master HB-bits
    if (master_status_dirty_ || status_write_next_) {
      data.type    = MessageType::WRITE_DATA;
      data.valueLB = 0x00;  // slave byte niet door ons gevuld
      data.valueHB =
          (ch_enable           ? (1 << 0) : 0) |
          (dhw_enable          ? (1 << 1) : 0) |
          (cooling_enable      ? (1 << 2) : 0) |
          (otc_active          ? (1 << 3) : 0) |
          (ch2_active          ? (1 << 4) : 0) |
          (summer_mode_active  ? (1 << 5) : 0) |
          (dhw_block           ? (1 << 6) : 0);
      master_status_dirty_ = false;
      status_write_next_   = false;   // volgende keer READ
    } else {
      data.type = MessageType::READ_DATA;
      status_write_next_ = true;      // volgende keer WRITE
    }
    return data;
  }



  // Next, we start with write requests from switches and other inputs,
  // because we would want to write that data if it is available, rather than
  // request a read for that type (in the case that both read and write are
  // supported).
  switch (request_id) {
    OPENTHERM_SWITCH_MESSAGE_HANDLERS(OPENTHERM_MESSAGE_WRITE_MESSAGE, OPENTHERM_MESSAGE_WRITE_ENTITY, ,
                                      OPENTHERM_MESSAGE_WRITE_POSTSCRIPT, )
    OPENTHERM_NUMBER_MESSAGE_HANDLERS(OPENTHERM_MESSAGE_WRITE_MESSAGE, OPENTHERM_MESSAGE_WRITE_ENTITY, ,
                                      OPENTHERM_MESSAGE_WRITE_POSTSCRIPT, )
    OPENTHERM_OUTPUT_MESSAGE_HANDLERS(OPENTHERM_MESSAGE_WRITE_MESSAGE, OPENTHERM_MESSAGE_WRITE_ENTITY, ,
                                      OPENTHERM_MESSAGE_WRITE_POSTSCRIPT, )
    OPENTHERM_INPUT_SENSOR_MESSAGE_HANDLERS(OPENTHERM_MESSAGE_WRITE_MESSAGE, OPENTHERM_MESSAGE_WRITE_ENTITY, ,
                                            OPENTHERM_MESSAGE_WRITE_POSTSCRIPT, )
    OPENTHERM_SETTING_MESSAGE_HANDLERS(OPENTHERM_MESSAGE_WRITE_MESSAGE, OPENTHERM_MESSAGE_WRITE_SETTING, ,
                                       OPENTHERM_MESSAGE_WRITE_POSTSCRIPT, )
    default:
      break;
  }

  // Finally, handle the simple read requests, which only change with the message id.
  switch (request_id) {
    OPENTHERM_SENSOR_MESSAGE_HANDLERS(OPENTHERM_MESSAGE_READ_MESSAGE, OPENTHERM_IGNORE, , , )
    default:
      break;
  }
  switch (request_id) {
    OPENTHERM_BINARY_SENSOR_MESSAGE_HANDLERS(OPENTHERM_MESSAGE_READ_MESSAGE, OPENTHERM_IGNORE, , , )
    default:
      break;
  }

  // And if we get here, a message was requested which somehow wasn't handled.
  // This shouldn't happen due to the way the defines are configured, so we
  // log an error and just return a 0 message.
  ESP_LOGE(TAG, "Tried to create a request with unknown id %d. This should never happen, so please open an issue.",
           request_id);
  return {};
}

OpenthermHub::OpenthermHub() : Component(), in_pin_{}, out_pin_{} {}

void OpenthermHub::process_response(OpenthermData &data) {
  ESP_LOGD(TAG, "Received OpenTherm response with id %d (%s)", data.id,
           this->opentherm_->message_id_to_str((MessageId) data.id));
  this->opentherm_->debug_data(data);

  switch (data.id) {
    OPENTHERM_SENSOR_MESSAGE_HANDLERS(OPENTHERM_MESSAGE_RESPONSE_MESSAGE, OPENTHERM_MESSAGE_RESPONSE_ENTITY, ,
                                      OPENTHERM_MESSAGE_RESPONSE_POSTSCRIPT, )
  }
  switch (data.id) {
    OPENTHERM_BINARY_SENSOR_MESSAGE_HANDLERS(OPENTHERM_MESSAGE_RESPONSE_MESSAGE, OPENTHERM_MESSAGE_RESPONSE_ENTITY, ,
                                             OPENTHERM_MESSAGE_RESPONSE_POSTSCRIPT, )
  }
}

void OpenthermHub::setup() {
  this->opentherm_ = make_unique<OpenTherm>(this->in_pin_, this->out_pin_);
  if (!this->opentherm_->initialize()) {
    ESP_LOGE(TAG, "Failed to initialize OpenTherm protocol. See previous log messages for details.");
    this->mark_failed();
    return;
  }

  // Elke seconde minstens één bericht — status is verplicht.
  this->add_repeating_message(MessageId::STATUS);

  // Voeg de drie belangrijkste berichten toe in de gewenste volgorde:
  this->add_repeating_message(static_cast<MessageId>(0));   // 0x00 STATUS
  this->add_repeating_message(static_cast<MessageId>(1));   // 0x01 CH setpoint (WRITE 10°C)
  this->add_repeating_message(static_cast<MessageId>(16));  // 0x10 Room setpoint (WRITE 18–19°C)

  // Voor debug en consistent gedrag
  ESP_LOGI(TAG, "Repeating messages configured: STATUS (0), CH_SETPOINT (1), ROOM_SETPOINT (16)");

  this->write_initial_messages_(this->messages_);
  this->message_iterator_ = this->messages_.begin();
}

void OpenthermHub::on_shutdown() { this->opentherm_->stop(); }

// Disabling clang-tidy for this particular line since it keeps removing the trailing underscore (bug?)
void OpenthermHub::write_initial_messages_(std::vector<MessageId> &target) {  // NOLINT
  std::vector<std::pair<MessageId, uint8_t>> sorted;
  std::copy_if(this->configured_messages_.begin(), this->configured_messages_.end(), std::back_inserter(sorted),
               [](const std::pair<MessageId, uint8_t> &pair) { return pair.second < REPEATING_MESSAGE_ORDER; });
  std::sort(sorted.begin(), sorted.end(),
            [](const std::pair<MessageId, uint8_t> &a, const std::pair<MessageId, uint8_t> &b) {
              return a.second < b.second;
            });

  target.clear();
  std::transform(sorted.begin(), sorted.end(), std::back_inserter(target),
                 [](const std::pair<MessageId, uint8_t> &pair) { return pair.first; });
}

// Disabling clang-tidy for this particular line since it keeps removing the trailing underscore (bug?)
void OpenthermHub::write_repeating_messages_(std::vector<MessageId> &target) {  // NOLINT
  target.clear();
  for (auto const &pair : this->configured_messages_) {
    if (pair.second == REPEATING_MESSAGE_ORDER) {
      target.push_back(pair.first);
    }
  }
}

void OpenthermHub::loop() {
  if (this->sync_mode_) {
    this->sync_loop_();
    return;
  }

  auto cur_time = millis();
  auto const cur_mode = this->opentherm_->get_mode();

  if (this->handle_error_(cur_mode)) {
    return;
  }

  switch (cur_mode) {
    case OperationMode::WRITE:
    case OperationMode::READ:
    case OperationMode::LISTEN:
      break;
    case OperationMode::IDLE:
      this->check_timings_(cur_time);
      if (this->should_skip_loop_(cur_time)) {
        break;
      }
      this->start_conversation_();
      break;
    case OperationMode::SENT:
      // Message sent, now listen for the response.
      this->opentherm_->listen();
      break;
    case OperationMode::RECEIVED:
      this->read_response_();
      break;
    default:
      break;
  }
  this->last_mode_ = cur_mode;
}

bool OpenthermHub::handle_error_(OperationMode mode) {
  switch (mode) {
    case OperationMode::ERROR_PROTOCOL:
      // Protocol error can happen only while reading boiler response.
      this->handle_protocol_error_();
      return true;
    case OperationMode::ERROR_TIMEOUT:
      // Timeout error might happen while we wait for device to respond.
      this->handle_timeout_error_();
      return true;
    case OperationMode::ERROR_TIMER:
      // Timer error can happen only on ESP32.
      this->handle_timer_error_();
      return true;
    default:
      return false;
  }
}

void OpenthermHub::sync_loop_() {
  if (!this->opentherm_->is_idle()) {
    ESP_LOGE(TAG, "OpenTherm is not idle at the start of the loop");
    return;
  }

  auto cur_time = millis();

  this->check_timings_(cur_time);

  if (this->should_skip_loop_(cur_time)) {
    return;
  }

  this->start_conversation_();
  // There may be a timer error at this point
  if (this->handle_error_(this->opentherm_->get_mode())) {
    return;
  }

  // Spin while message is being sent to device
  if (!this->spin_wait_(1150, [&] { return this->opentherm_->is_active(); })) {
    ESP_LOGE(TAG, "Hub timeout triggered during send");
    this->stop_opentherm_();
    return;
  }

  // Check for errors and ensure we are in the right state (message sent successfully)
  if (this->handle_error_(this->opentherm_->get_mode())) {
    return;
  } else if (!this->opentherm_->is_sent()) {
    ESP_LOGW(TAG, "Unexpected state after sending request: %s",
             this->opentherm_->operation_mode_to_str(this->opentherm_->get_mode()));
    this->stop_opentherm_();
    return;
  }

  // Listen for the response
  this->opentherm_->listen();
  // There may be a timer error at this point
  if (this->handle_error_(this->opentherm_->get_mode())) {
    return;
  }

  // Spin while response is being received
  if (!this->spin_wait_(1150, [&] { return this->opentherm_->is_active(); })) {
    ESP_LOGE(TAG, "Hub timeout triggered during receive");
    this->stop_opentherm_();
    return;
  }

  // Check for errors and ensure we are in the right state (message received successfully)
  if (this->handle_error_(this->opentherm_->get_mode())) {
    return;
  } else if (!this->opentherm_->has_message()) {
    ESP_LOGW(TAG, "Unexpected state after receiving response: %s",
             this->opentherm_->operation_mode_to_str(this->opentherm_->get_mode()));
    this->stop_opentherm_();
    return;
  }

  this->read_response_();
}

void OpenthermHub::check_timings_(uint32_t cur_time) {
  if (this->last_conversation_start_ > 0 && (cur_time - this->last_conversation_start_) > 1150) {
    ESP_LOGW(TAG,
             "%d ms elapsed since the start of the last convo, but 1150 ms are allowed at maximum. Look at other "
             "components that might slow the loop down.",
             (int) (cur_time - this->last_conversation_start_));
  }
}

bool OpenthermHub::should_skip_loop_(uint32_t cur_time) const {
  if (this->last_conversation_end_ > 0 && (cur_time - this->last_conversation_end_) < 100) {
    ESP_LOGV(TAG, "Less than 100 ms elapsed since last convo, skipping this iteration");
    return true;
  }

  return false;
}

void OpenthermHub::start_conversation_() {
  if (this->message_iterator_ == this->messages_.end()) {
    if (this->sending_initial_) {
      this->sending_initial_ = false;
      this->write_repeating_messages_(this->messages_);
    }
    this->message_iterator_ = this->messages_.begin();
  }

  auto request = this->build_request_(*this->message_iterator_);

  this->before_send_callback_.call(request);

  ESP_LOGD(TAG, "Sending request with id %d (%s)", request.id,
           this->opentherm_->message_id_to_str((MessageId) request.id));
  this->opentherm_->debug_data(request);
  // Send the request
  this->last_conversation_start_ = millis();
  this->opentherm_->send(request);
}

void OpenthermHub::read_response_() {
  OpenthermData response;
  if (!this->opentherm_->get_message(response)) {
    ESP_LOGW(TAG, "Couldn't get the response, but flags indicated success. This is a bug.");
    this->stop_opentherm_();
    return;
  }

  this->stop_opentherm_();

  this->before_process_response_callback_.call(response);
  this->process_response(response);

  this->message_iterator_++;
}

void OpenthermHub::stop_opentherm_() {
  this->opentherm_->stop();
  this->last_conversation_end_ = millis();
}

void OpenthermHub::handle_protocol_error_() {
  OpenThermError error;
  this->opentherm_->get_protocol_error(error);
  ESP_LOGW(TAG, "Protocol error occured while receiving response: %s",
           this->opentherm_->protocol_error_to_str(error.error_type));
  this->opentherm_->debug_error(error);
  this->stop_opentherm_();
}

void OpenthermHub::handle_timeout_error_() {
  ESP_LOGW(TAG, "Timeout while waiting for response from device");
  this->stop_opentherm_();
}

void OpenthermHub::handle_timer_error_() {
  this->opentherm_->report_and_reset_timer_error();
  this->stop_opentherm_();
  // Timer error is critical, there is no point in retrying.
  this->mark_failed();
}

void OpenthermHub::dump_config() {
  std::vector<MessageId> initial_messages;
  std::vector<MessageId> repeating_messages;
  this->write_initial_messages_(initial_messages);
  this->write_repeating_messages_(repeating_messages);

  ESP_LOGCONFIG(TAG, "OpenTherm:");
  LOG_PIN("  In: ", this->in_pin_);
  LOG_PIN("  Out: ", this->out_pin_);
  ESP_LOGCONFIG(TAG,
                "  Sync mode: %s\n"
                "  Sensors: %s\n"
                "  Binary sensors: %s\n"
                "  Switches: %s\n"
                "  Input sensors: %s\n"
                "  Outputs: %s\n"
                "  Numbers: %s",
                YESNO(this->sync_mode_), SHOW(OPENTHERM_SENSOR_LIST(ID, )), SHOW(OPENTHERM_BINARY_SENSOR_LIST(ID, )),
                SHOW(OPENTHERM_SWITCH_LIST(ID, )), SHOW(OPENTHERM_INPUT_SENSOR_LIST(ID, )),
                SHOW(OPENTHERM_OUTPUT_LIST(ID, )), SHOW(OPENTHERM_NUMBER_LIST(ID, )));
  ESP_LOGCONFIG(TAG, "  Initial requests:");
  for (auto type : initial_messages) {
    ESP_LOGCONFIG(TAG, "  - %d (%s)", type, this->opentherm_->message_id_to_str(type));
  }
  ESP_LOGCONFIG(TAG, "  Repeating requests:");
  for (auto type : repeating_messages) {
    ESP_LOGCONFIG(TAG, "  - %d (%s)", type, this->opentherm_->message_id_to_str(type));
  }
}

}  // namespace opentherm
}  // namespace esphome
