import style from './UserPassingTest.module.css'
import { useNavigate } from "react-router-dom"

const UserPassingTestTmp = () => {
  const navigate = useNavigate();
  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>Question 2/35</div>
        <div className={style.text}>
          <label className={style.qText}>
            2. Выберите задачи, которые необходимо решить для достижения основной цели БЖД
          </label>
          <ul>
            <li>
              <input type="checkbox" id="1" name="options" /> идентификация негативных факторов окружающей среды
            </li>
            <li>
              <input type="checkbox" id="2" name="options" /> количественная оценка воздействующих негативных воздействий
            </li>
            <li>
              <input type="checkbox" id="3" name="options" /> прогнозирование влияния на человека внешних факторов
            </li>
            <li>
              <input type="checkbox" id="4" name="options" /> выбор способов снижения негативного воздействия внешних факторов на человека
            </li>
            <li>
              <input type="checkbox" id="4" name="options" /> расчёт обеспеченности работников средствами индивидуальной защиты
            </li>
          </ul>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate("/user-result-test")} >Next</button>
        </div>
      </div>
  );
}

export default UserPassingTestTmp;
