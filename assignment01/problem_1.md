# Embedded Device Example

Using the telegraph example, and the challenges listed in the module as reference, and describe another device that you would like to discuss. Describe how you think its embedded system works, and what design challenges it presents.

## Automatic Break System in Cars

Automatic break systems in cars can save lifes and thus have to be built right. They can avoid collisions and thus prevent fatal accidents. I think for these to work, there are probably a lot of onboard sensors that work in tandem like cameras, laser, radar, etc. Current data is read from these sensors must be read with high throuhput and low latency so that brakes can be applied in time in case the sensors "think" that a collision can occur. These systems have to be upgradable through software as there may be a "road condition" that the testers did not think of at the time of design and this also mandates that one should be able to run diagnosis on them. Security of such systems is also of prime importance because if hackers are able to break into such devices that result can be catastrophic!

All the above design challanges will add to the cost of the eventual products and so I think that automatic break systems in car must not be cheap!