.PHONY: clean All

All:
	@echo "----------Building project:[ SensorTriggeredCamera - Debug ]----------"
	@"$(MAKE)" -f  "SensorTriggeredCamera.mk"
clean:
	@echo "----------Cleaning project:[ SensorTriggeredCamera - Debug ]----------"
	@"$(MAKE)" -f  "SensorTriggeredCamera.mk" clean
