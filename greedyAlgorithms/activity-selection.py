class Activity:
    def __init__(self, id, start, finish):
        super().__init__()
        self.id = id
        self.startTime = start
        self.finishTime = finish        

    def print_value(self):
        print(f"{self.id} {self.startTime} {self.finishTime}")
    
    def is_conflict(self, activity1):
        return self.startTime < activity1.finishTime
    

class ActivitySelection:
    def __init__(self, activities):
        super().__init__()
        self.activities = activities
    
    def select_activities(self):
        solution = []
        solution.append(self.activities[0])
        i = 1
        j = 0 # track for selected activity
        while i < len(self.activities):
            if not self.activities[i].is_conflict(self.activities[j]):
                solution.append(self.activities[i])
                j = i   
            i = i + 1             
        return solution


activities = [
    Activity(1, 2, 3),
    Activity(2, 2, 5),
    Activity(3, 4, 7),
    Activity(4, 1, 8),
    Activity(5, 5, 9),
    Activity(6, 8, 10),
    Activity(7, 9, 11),
    Activity(8, 11, 14),
    Activity(9, 13, 16),
]

act_selection = ActivitySelection(activities)
result = act_selection.select_activities()
for activity in result:
    activity.print_value()