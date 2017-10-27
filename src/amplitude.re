type t;

type event 'a 'b =
  Js.t {
    .
    eventType : string,
    userId : string,
    deviceId : Js.nullable string,
    sessionId : Js.nullable string,
    eventProperties : Js.Dict.t 'a,
    userProperties : Js.Dict.t 'b
  };

external make : string => t = "amplitude" [@@bs.module] [@@bs.new];

external track : event 'a 'b => unit = "" [@@bs.send.pipe : t];

external trackMany : array (event 'a 'b) => unit = "track" [@@bs.send.pipe : t];

let makeEvent ::eventType ::userId ::deviceId=? ::sessionId=? ::eventProperties ::userProperties () => {
  "eventType": eventType,
  "userId": userId,
  "deviceId": Js.Nullable.from_opt deviceId,
  "sessionId": Js.Nullable.from_opt sessionId,
  "eventProperties": eventProperties,
  "userProperties": userProperties
};
