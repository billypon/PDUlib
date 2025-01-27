#include <Arduino.h>
#include <pdulib.h>

PDU mypdu = PDU();
// ascii yen aleph spade ace_of_spaces hebrew
char const *inpdu[] = {
  "07917952140230F2040C917952777777770008120170016131212200680065006C006C006F003000A505D02660D83CDCA1D83DDE0005E905DC05D505DD",
  "07917952140230F2040C9179527777777700001201216123732106CA405B8D6000", //    GSM 7 bit
  "07917952939899F9240C917952630247660000120151113404210A814D79C3DBF8C2E231",  // includes escape euro
  "07917952140230F2040C91795277777777000812012161238121180061006200630064D83CDF56D83DDE0305D005D105D205D3",  // hebrew emojis
  "07917952140230F2040C91795277777777000012012161335221A061F1985C369FD169F59ADD76BFE171F99C5EB7DFF1797D503824168D476452B964369D4F68543AA556AD576C561B168FC965F3199D56AFD96DF71B1E97CFE975FB1D9FD707854362D1784426954B66D3F98446A5536AD57AC566B561F1985C369FD169F59ADD76BFE171F99C5EB7DFF1797D503824168D476452B964369D4F68543AA556AD576C561B93CD68" // full length
};
void setup() {
  Serial.begin(9600);
#ifdef PM
  Serial.println("Using PM");
#else
  Serial.println("Not using PM");
#endif
  for (int i=0; i< sizeof(inpdu)/sizeof(const char *); i++) {
    if (mypdu.decodePDU(inpdu[i])) {
      Serial.println("-------------------------------");
      Serial.println(mypdu.getSCAnumber());
      Serial.println(mypdu.getSender());
      Serial.println(mypdu.getTimeStamp());
      Serial.println(mypdu.getText());
    }
    else
      Serial.println("failed");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}