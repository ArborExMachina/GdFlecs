extends Node2D

var ecs: ECSWorld

#class VelComp extends GDComponent:
#	var vec: Vector2


func _ready():
	ecs = $ECSWorld
	
	var comps = ClassDB.get_inheriters_from_class("GDComponent")
	print(comps)
	
	print(ClassDB.class_exists("VelComp"))

#	var ball = Ball.new()
#	add_child(ball)
