#include "YamlNodeFixture.h"

void YamlNodeFixture::SetUp() {
   this->node["int"] = 1;
   this->node["float"] = 1.1;
}

void YamlNodeFixture::TearDown() {
   // Cleanup if needed
}
