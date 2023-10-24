//
// Created by Michael Molchanov on 24.10.2023.
//

#include "IWorker.h"
#include "Worker.h"
#include "fruit/fruit.h"

fruit::Component<IWorker> getIWorkerComponent(){
    return fruit::createComponent().bind<IWorker, Worker>();
};
