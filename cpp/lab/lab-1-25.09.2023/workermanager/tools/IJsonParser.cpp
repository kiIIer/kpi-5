#include "fruit/fruit.h"
#include "IJsonParser.h"
#include "JsonParser.h"

fruit::Component <IJsonParser> getIJsonParserComponent() {
    return fruit::createComponent().bind<IJsonParser, JsonParser>();
}
