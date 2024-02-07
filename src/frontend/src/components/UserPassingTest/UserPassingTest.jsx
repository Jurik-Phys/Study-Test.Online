import style from './UserPassingTest.module.css'
import { useNavigate } from "react-router-dom"

const UserPassingTest = () => {
  const navigate = useNavigate();
  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>Question 1/35</div>
        <div className={style.text}>
          <label className={style.qText}>
            1. Основная цель учебного курса БЖД состоит в ...
          </label>
          <ul>
            <li>
              <input type="radio" id="1" name="options" checked /> формировании знаний направленных на снижение смертности и потерь здоровья людей от внешних факторов и причин
            </li>
            <li>
              <input type="radio" id="2" name="options" /> формировании знаний направленных на добровольное и/или принудительное ограничение доступа людей к объектам опасности
            </li>
            <li>
              <input type="radio" id="3" name="options" /> формировании знаний направленных на предотвращение смертности и потерь здоровья людей от внешних факторов и причин
            </li>
            <li>
              <input type="radio" id="4" name="options" />
              формировании знаний направленных на обеспечение комфортных условий труда на рабочем месте
            </li>
          </ul>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate("/user-passing-test-tmp")} >Next</button>
        </div>
      </div>

  );
}

export default UserPassingTest;
