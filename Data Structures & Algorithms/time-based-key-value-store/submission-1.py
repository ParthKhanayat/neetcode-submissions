class TimeMap:
    def __init__(self):
        self.objects = dict()  # using hashmap as data structure

    def set(self, key: str, value: str, timestamp: int) -> None:
        if (
            key not in self.objects
        ):  # this is because we are storing pairs as list which is stored inside a main list [[value,timestamp],.....]
            self.objects[key] = []
        self.objects[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        res = ""  # if nothing found then return empty string
        values = self.objects.get(key, [])
        # all timestamps are in increasing order so we can use binary search
        # a solution better than O(n) is binary search O(logn)
        l, r = 0, len(values) - 1
        while l <= r:
            m = (l + r) // 2
            if values[m][1] <= timestamp:  # [m][1] : timestamp
                res = values[m][0]  # [m][0] : value
                l = (
                    m + 1
                )  # we are not immediately returning it, we are still updating,if we find any other value later
            else:  # if >timestamp
                r = m - 1
        return res
