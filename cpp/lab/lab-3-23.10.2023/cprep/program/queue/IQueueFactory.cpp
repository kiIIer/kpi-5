//
// Created by Michael Molchanov on 24.10.2023.
//

#include "IQueueFactory.h"
#include "QueueFactory.h"
#include "fruit/fruit.h"

fruit::Component<IQueueFactory> getIQueueFactoryComponent(){
    return fruit::createComponent().bind<IQueueFactory, QueueFactory>();
};
