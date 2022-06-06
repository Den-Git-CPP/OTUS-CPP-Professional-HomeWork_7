#pragma once
class Observer
{
public:
	virtual void set_data(Accumulator_Commands* accumulate_for_file)=0;
	virtual void notify() = 0;
};