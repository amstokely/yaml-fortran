#include "YamlFortranFixture.h"

void YamlFortranFixture::SetUp() {
   this->row1["x"] = 1.0f;
   this->row1["y"] = 0.0f;
   this->row1["z"] = 0.0f;
   this->row2["x"] = 0.0f;
   this->row2["y"] = 1.0f;
   this->row2["z"] = 0.0f;
   this->row3["x"] = 0.0f;
   this->row3["y"] = 0.0f;
   this->row3["z"] = 1.0f;
   this->mat3Node["row1"] = this->row1;
   this->mat3Node["row2"] = this->row2;
   this->mat3Node["row3"] = this->row3;
   this->mat3Node["sum"] = 1.0f;
}

void YamlFortranFixture::TearDown() {
   // Cleanup if needed
}
