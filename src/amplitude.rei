type t;

type event 'a 'b =
  Js.t {
    .
    deviceId : Js.nullable string,
    eventProperties : Js.Dict.t 'a,
    eventType : string,
    sessionId : Js.nullable string,
    userId : string,
    userProperties : Js.Dict.t 'b
  };

let make: string => t;

let track: event 'a 'b => t => unit;

let trackMany: array (event 'a 'b) => t => unit;

let makeEvent:
  eventType::string =>
  userId::string =>
  deviceId::string? =>
  sessionId::string? =>
  eventProperties::Js.Dict.t 'a =>
  userProperties::Js.Dict.t 'b =>
  unit =>
  event 'a 'b;
