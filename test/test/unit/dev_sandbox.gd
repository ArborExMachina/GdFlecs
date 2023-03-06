extends GutTest

var ecs: ECSWorld = null

func before_all():
	pass

func before_each():
	ecs = ECSWorld.new()

func after_each():
	ecs.queue_free()

func after_all():
	pass


func test_run_sandbox():
	pass
