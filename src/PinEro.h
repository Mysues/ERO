#pragma once

struct PinERO
{
    PinERO() {}

    PinERO(int *motorPin, int *signalPin, int beeperPin, int speed_ctrlPin, int txPin, int rxPin)
    {
        this->motorPin = motorPin;
        this->signalPin = signalPin;
        this->beeperPin = beeperPin;
        this->speed_ctrlPin = speed_ctrlPin;

        this->txPin = txPin;
        this->rxPin = rxPin;
    }

    int *motorPin;
    int *signalPin;

    int beeperPin;
    int speed_ctrlPin;

    int txPin;
    int rxPin;
};